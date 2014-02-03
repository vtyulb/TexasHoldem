#ifndef FULLSITUATION_H
#define FULLSITUATION_H

#include <situation.h>

class FullSituation : public Situation
{
public:
    FullSituation();
    FullSituation(Hand hand, Table table, int res);
    int res;
};

#endif // FULLSITUATION_H
