#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char name[][10] = {
        "Harvey",
        "Kevin",
        "Bam",
        "Eugene",
        "Win",
        "Natty",
        "Will",
        "Tegan",
        "Numpun",
        "Anthony",
        "Irene",
        "Judy",
        "Rebecca",
        "Athena",
        "Bob",
        "Jamie",
        "Ilsa",
        "Ethan",
        "Yang",
        "Yvonne",
        "Ryan",
        "William",
        "Mako",
        "Akari",
        "Mind",
        "Clara",
        "Vania",
        "Rita",
        "Kana",
        "Masa",
        "Stephanie",
        "Rose",
        "Julia",
        "Ryan",
        "Jess",
        "Leo",
        "Claire",
        "Aries",
        "Benson",
        "Tim",
        "Michael",
        "Casper",
        "Shihzo",
        "Daniel",
        "Avic",
        "Nile",
        "Plan",
        "Alexander",
        "Kai",
        "David",
        "Rimuru",
        "Bryant",
        "Fable",
        "Natalie",
    };
    int random[54] = {0};
    for (int i = 0; i < 54; i++) {
        random[i] = i;
    }
    srand(time(NULL));
    for(int i = 0; i < 54; i++){
        int i_rand = rand() % 60;
        int temp = random[i];
        random[i] = random[i_rand];
        random[i_rand] = temp;
    }
    for(int i = 0; i < 54; i++){
        printf("%s", name[random[i]]);
        while(getchar() != '\n');
    }
}