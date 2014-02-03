#include "card.h"

Card::Card() {
    valid = false;
}

bool Card::operator <(const Card &c) {
    if (value < c.value)
        return true;
    else if (value > c.value)
        return false;
    else
        return suit < c.value;
}
