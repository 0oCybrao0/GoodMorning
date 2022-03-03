#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define SUITS 4
#define FACES 13
#define CARDS 52
#define HAND 5
typedef struct cards {
    int suit, face;
} cards;

void shuffle(cards *);
void swap(cards *, cards *);
int compare(const void *, const void *);
bool judge(cards *);
bool straight_flush(cards *);
bool four_of_a_kind(int *);
bool full_house(int *);
bool flush(cards *);
bool straight(cards *);
bool three_of_a_kind(int *);
bool two_pairs(int *);
bool one_pair(int *);

const char *suits[SUITS] =
    {"Spades", "Hearts", "Diamonds", "Clubs"};
const char *faces[FACES] =
    {"Deuce", "Three", "Four",
     "Five", "Six", "Seven", "Eight",
     "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

int main() {
    cards deck[52] = {0};
    cards hand[5] = {0};
    for (int i = 0; i < SUITS; i++) {
        for (int j = 0; j < FACES; j++) {
            deck[i * 13 + j].suit = i;
            deck[i * 13 + j].face = j;
        }
    }
    while (1) {
        shuffle(deck);
        qsort(deck, 5, sizeof(cards), compare);
        for (int i = 0; i < 5; i++) {
            printf("%s of %s\n", faces[deck[i].face], suits[deck[i].suit]);
            hand[i] = deck[i];
        }
        if (!judge(hand)) {
            break;
        }
    }
}

void shuffle(cards *deck) {
    srand(time(NULL) + getpid());
    for (int i = 0; i < CARDS; i++) {
        swap(&deck[i], &deck[rand() % CARDS]);
    }
}

void swap(cards *a, cards *b) {
    cards temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *a, const void *b) {
    cards a_ = *(cards *)a;
    cards b_ = *(cards *)b;
    if (a_.face == b_.face) {
        return a_.suit - b_.suit;
    }
    return a_.face - b_.face;
}

bool judge(cards *hand) {
    int frequency[13] = {0};
    for (int i = 0; i < HAND; i++) {
        frequency[hand[i].face]++;
    }
    if (!straight_flush(hand)) {
        if (!four_of_a_kind(frequency)) {
            if (!full_house(frequency)) {
                if (!flush(hand)) {
                    if (!straight(hand)) {
                        if (!three_of_a_kind(frequency)) {
                            if (!two_pairs(frequency)) {
                                if (!one_pair(frequency)) {
                                    printf("You have high cards\n");
                                }
                            }
                        }
                    }
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

bool straight_flush(cards *hand) {
    int temp_suit = hand[0].suit;
    int temp_face = hand[0].face;
    for (int i = 1; i < HAND; i++) {
        if (hand[i].face != ++temp_face) {
            return false;
        }
        if (hand[i].suit != temp_suit) {
            return false;
        }
    }
    printf("You have a %s straigh flush from %s to %s\n", suits[temp_suit], faces[hand[0].face], faces[hand[4].face]);
    return true;
}

bool four_of_a_kind(int *frequency) {
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 4) {
            printf("You have four of %s\n", faces[i]);
            return true;
        }
    }
    return false;
}

bool full_house(int *frequency) {
    int two = 0, three = 0, flag_two = 0, flag_three;
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 3) {
            three = i;
            flag_three = 1;
        } else if (frequency[i] == 2) {
            two = i;
            flag_two = 1;
        }
    }
    if (flag_two + flag_three == 2) {
        printf("You have a full house of %s with %s pair\n", faces[three], faces[two]);
        return true;
    }
    return false;
}

bool flush(cards *hand) {
    int temp = hand[0].suit;
    for (int i = 1; i < HAND; i++) {
        if (hand[i].suit != temp) {
            return false;
        }
    }
    printf("You have a flush of %s\n", suits[temp]);
    return true;
}

bool straight(cards *hand) {
    int temp = hand[0].face;
    for (int i = 1; i < HAND; i++) {
        if (++temp != hand[i].face) {
            return false;
        }
    }
    printf("You have a straight from %s to %s\n", faces[hand[0].face], faces[hand[4].face]);
    return true;
}

bool three_of_a_kind(int *frequency) {
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 3) {
            printf("You have three of %s\n", faces[i]);
            return true;
        }
    }
    return false;
}

bool two_pairs(int *frequency) {
    int first_pair = 0, second_pair = 0, flag = 0;
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 2 && flag == 0) {
            first_pair = i;
            flag++;
        } else if (frequency[i] == 2 && flag == 1) {
            second_pair = i;
            flag++;
            break;
        }
    }
    if (flag == 2) {
        printf("You have two pairs of %s and %s\n", faces[first_pair], faces[second_pair]);
        return true;
    }
    return false;
}

bool one_pair(int *frequency) {
    for (int i = 0; i < FACES; i++) {
        if (frequency[i] == 2) {
            printf("You have a pair of %s\n", faces[i]);
            return true;
        }
    }
    return false;
}