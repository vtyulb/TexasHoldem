#ifndef HAND_H
#define HAND_H

#include <QObject>
#include <card.h>

class Hand
{
public:
    explicit Hand();

    Card cards[2];

private:

signals:

public slots:

};

#endif // HAND_H
