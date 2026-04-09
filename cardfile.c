#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 100

typedef struct {
    char name[50];
    char description[200];
} Card;

Card cards[MAX_CARDS];
int card_count = 0;

void add_card(const char *name, const char *description) {
    if (card_count < MAX_CARDS) {
        strcpy(cards[card_count].name, name);
        strcpy(cards[card_count].description, description);
        card_count++;
        printf("Card added: %s\n", name);
    } else {
        printf("Card limit reached. Cannot add more cards.\n");
    }
}

void modify_card(int index, const char *name, const char *description) {
    if (index >= 0 && index < card_count) {
        strcpy(cards[index].name, name);
        strcpy(cards[index].description, description);
        printf("Card modified at index %d: %s\n", index, name);
    } else {
        printf("Invalid index.\n");
    }
}

void delete_card(int index) {
    if (index >= 0 && index < card_count) {
        for (int i = index; i < card_count - 1; i++) {
            cards[i] = cards[i + 1];
        }
        card_count--;
        printf("Card deleted at index %d.\n", index);
    } else {
        printf("Invalid index.\n");
    }
}

void view_cards() {
    for (int i = 0; i < card_count; i++) {
        printf("Card %d: %s - %s\n", i, cards[i].name, cards[i].description);
    }
}

int main() {
    add_card("Sample Card 1", "This is a sample card description.");
    add_card("Sample Card 2", "This is another sample card.");

    view_cards();

    modify_card(0, "Updated Card 1", "Updated description for card 1.");
    delete_card(1);

    view_cards();

    return 0;
}