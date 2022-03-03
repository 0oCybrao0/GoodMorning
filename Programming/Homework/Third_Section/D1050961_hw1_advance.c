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
void judge(cards *);
bool flush(cards *);
bool straight(cards *);

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
    shuffle(deck);
    qsort(deck, 5, sizeof(cards), compare);
    for (int i = 0; i < 5; i++) {
        printf("%s of %s\n", faces[deck[i].face], suits[deck[i].suit]);
        hand[i] = deck[i];
    }
    judge(hand);
    return 0;
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

void judge(cards *hand) {
    flush(hand);
    straight(hand);
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