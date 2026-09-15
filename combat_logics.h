#pragma once

#include "ae_core.h"
#include "chara.h"
using namespace ae_core;

namespace combat_logics {
    const aen LUC_BASE = AE_numstr("100");

    aen stepForward(aen baseSpeed, aen agi) {
        return AE_div(baseSpeed, agi);
    }

    aen damageDealt(aen offensivePower, aen defensivePower) {
        return AE_div(offensivePower, AE_pow2(AE_div(defensivePower, offensivePower + defensivePower)));
    }

    bool binaryLuckRoll(aen luc_1, aen luc_2) {
        return (AE_rand() % (luc_1 + luc_2) >= luc_2);
    }

    bool unaryLuckRoll(aen luc) {
        return binaryLuckRoll(luc, LUC_BASE);
    }
}