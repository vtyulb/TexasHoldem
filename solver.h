#ifndef SOLVER_H
#define SOLVER_H

#include <card.h>
#include <table.h>
#include <hand.h>
#include <calculator.h>
#include <situation.h>
#include <fullsituation.h>
#include <threader.h>

#include <QMutex>
#include <QVector>

class Threader;
class Solver
{
public:
    Solver(Situation);

    void solve();
    long long wins;
    long long louses;
    double winrate;

    QMutex mutex;
    void atomicIncrease(int);
    QVector<FullSituation> problems;

private:
    Hand hand, enemyHand;
    Table table;
    bool matrix[15][4];
    void completeTable(int level);
    void completeHand(int res, int level);
};

#endif // SOLVER_H
