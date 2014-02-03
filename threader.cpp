#include "threader.h"

Threader::Threader(int from, int to, Solver *solver, QObject *parent): QThread(parent),
    from(from),
    to(to),
    solver(solver)
{
}

void Threader::run() {
    for (int i = from; i < to; i++) {
        Calculator calc(solver->problems[i]);
        solver->atomicIncrease(solver->problems[i].res > calc.calculate());
    }
}
