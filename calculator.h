#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <hand.h>
#include <table.h>
#include <situation.h>

class Calculator
{
public:
    explicit Calculator(Situation);
    int calculate();
    int result();

private:
    int res;
    Card cards[7];
    int has(int value);
    int max(int, int);

signals:

public slots:

};

#endif // CALCULATOR_H
