#include "fullsituation.h"

FullSituation::FullSituation(Hand hand, Table table, int res):
    Situation(hand, table),
    res(res) {

}

FullSituation::FullSituation() {}
