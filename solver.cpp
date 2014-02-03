#include "solver.h"
#include <QDebug>

const int numberThreads = 8;

Solver::Solver(Situation s):
    hand(s.hand),
    table(s.table) {

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 4; j++)
            matrix[i][j] = false;

    for (int i = 0; i < 2; i++)
        matrix[hand.cards[i].value][hand.cards[i].suit] = true;

    for (int i = 0; i < 5; i++)
        if (table.cards[i].valid)
            matrix[table.cards[i].value][table.cards[i].suit] = true;

    wins = 0;
    louses = 0;
}

void Solver::solve() {
    completeTable(0);

    int number = problems.size() / numberThreads;

    Threader *threads[numberThreads];
    for (int i = 0; i < numberThreads; i++) {
        threads[i] = new Threader(i * number, (i + 1) * number, this);
        threads[i]->start();
    }

    for (int i = 0; i < numberThreads; i++)
        while (!threads[i]->wait(10050000));

    winrate = wins/double(wins + louses);
}

void Solver::completeHand(int res, int level) {
    if (level == 2) {
        problems.push_back(FullSituation(enemyHand, table, res));
    } else {
        for (int i = 2; i < 15; i++)
            for (int j = 0; j < 4; j++)
                if (!matrix[i][j]) {
                    matrix[i][j] = true;
                    enemyHand.cards[level].value = i;
                    enemyHand.cards[level].suit = (Suit)j;
                    completeHand(res, level + 1);
                    matrix[i][j] = false;
                }
    }
}

void Solver::completeTable(int level) {
    if (level == 5) {
        Calculator calc(Situation(hand, table));
        int res = calc.calculate();
        completeHand(res, 0);
    } else if (table.cards[level].valid)
        completeTable(level + 1);
    else {
        for (int i = 2; i < 15; i++)
            for (int j = 0; j < 4; j++)
                if (!matrix[i][j]) {
                    matrix[i][j] = true;
                    table.cards[level].value = i;
                    table.cards[level].suit = (Suit)j;
                    completeTable(level + 1);
                    matrix[i][j] = false;
                }
    }
}

void Solver::atomicIncrease(int a) {
    mutex.lock();
    if (a == 1)
        wins++;
    else
        louses++;
    mutex.unlock();
}
