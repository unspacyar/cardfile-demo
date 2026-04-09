#ifndef CARD_H
#define CARD_H

class Card {
public:
    Card();
    ~Card();
    void display();
private:
    int value;
    char suit;
};

#endif // CARD_H
