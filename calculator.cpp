#include "calculator.h"

const int flashstraight = 1000 * 1000 * 1000;
const int care = 1000 * 1000 * 100;
const int full = 1000 * 1000 * 10;
const int flash_c = 1000 * 1000; //cost
const int straight_c = 1000 * 100;
const int triple = 1000 * 10;
const int twopairs = 1000;
const int pair = 100;
const int kick = 10;


Calculator::Calculator(Situation s) {
    for (int i = 0; i < 5; i++)
        cards[i] = s.table.cards[i];

    cards[5] = s.hand.cards[0];
    cards[6] = s.hand.cards[1];
}

int Calculator::result() {
    return res;
}

int Calculator::calculate() {
    int flash = 0;
    int straight = has(2) && has(3) && has(4) && has(5) && has(14);

    int suits[4];
    for (int i = 0; i < 4; i++)
        suits[i] = 0;

    for (int i = 0; i < 7; i++)
        suits[cards[i].suit]++;

    for (int i = 0; i < 4; i++)
        if (suits[i] > 4)
            for (int j = 0; j < 7; j++)
                if (cards[j].suit == i)
                    if (cards[j].value > flash)
                        flash = cards[j].value;

    for (int i = 2; i < 11; i++) {
        bool win = true;
        for (int j = 0; j < 5; j++)
            win = win && has(j);

        if (win)
            straight = i;
    }

    res = (flash && straight) * flashstraight + straight;

    for (int i = 2; i < 15; i++)
        if (has(i) == 4)
            res = max(res, care + i);

    for (int i = 2; i < 15; i++)
        if (has(i) == 3)
            for (int j = 2; j < 15; j++)
                if (has(i) == 2)
                    res = max(res, full + i * 30 + j);

    res = max(res, flash * (flash_c + flash));
    res = max(res, straight * (straight_c + straight));

    for (int i = 2; i < 15; i++)
        if (has(i) == 3)
            res = max(res, triple + i);

    for (int i = 2; i < 15; i++)
        if (has(i) == 2)
            for (int j = i + 1; j < 15; j++)
                if (has(j) == 2)
                    res = max(res, twopairs + j * 30 + i);

    for (int i = 2; i < 15; i++)
        if (has(i) == 2)
            res = max(res, pair + i);

    for (int i = 2; i < 15; i++)
        if (has(i))
            res = max(res, kick + i);

    return res;
}

int Calculator::has(int value) {
    int res = 0;
    for (int i = 0; i < 7; i++)
        res += cards[i].value == value;

    return res;
}

int Calculator::max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
