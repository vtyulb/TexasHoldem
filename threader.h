#ifndef THREADER_H
#define THREADER_H

#include <QThread>
#include <fullsituation.h>
#include <solver.h>

class Solver;
class Threader : public QThread
{
    Q_OBJECT
public:
    explicit Threader(int from, int to, Solver *solver, QObject *parent = 0);

protected:
    void run();

private:
    int from;
    int to;
    Solver *solver;

signals:

public slots:

};

#endif // THREADER_H
