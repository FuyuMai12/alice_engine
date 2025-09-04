#pragma once

#include <random>
#include "chara.h"

namespace combat_logics {
    const __int64_t ONE      = 1'000'000'000LL;
    const __int16_t DEF_BASE = 100;
    const __int16_t LUC_BASE = 100;

    const __int64_t ALICE_ENGINE_SEED = 0x616c6963655f656e67696e65LL;
    const mt19937_64 rng64(ALICE_ENGINE_SEED);

    __int64_t stepForward(__int16_t baseSpeed, __int16_t agi) {
        return (ONE * baseSpeed / agi);
    }

    __int16_t damageDealt(__int16_t offensivePower, __int16_t defensivePower) {
        return (ONE * offensivePower * DEF_BASE / (DEF_BASE + defensivePower) + ONE / 2) / ONE;
    }

    bool binaryLuckRoll(__int16_t luc_1, __int16_t luc_2) {
        return (rng64() % (luc_1 + luc_2) >= luc_2);
    }

    bool unaryLuckRoll(__int16_t luc) {
        return binaryLuckRoll(luc, LUC_BASE);
    }
}