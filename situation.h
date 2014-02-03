#ifndef SITUATION_H
#define SITUATION_H

#include <hand.h>
#include <table.h>

class Situation
{
public:
    Situation();
    Situation(Hand hand, Table table);
    Hand hand;
    Table table;
};

#endif // SITUATION_H
