#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QPixmap>

enum Suit {
    Clubs,
    Diamonds,
    Hearts,
    Spades
};

class Card
{
public:
    explicit Card();
    int value;
    Suit suit;
    bool valid;

    QPixmap getImage();

    bool operator <(const Card &c);

signals:

public slots:

};

#endif // CARD_H
