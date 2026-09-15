#pragma once

#include "FR_math.h"
#include <random>

namespace ae_core {
    #define ALICE_ENGINE_DEFAULT_RADIX 12
    #define ALICE_ENGINE_SEED 0x616c6963655f656e67696e65LL
    using aen  = ::s32;
    using aenl = ::s64;
    std::mt19937 ae_generator(ALICE_ENGINE_SEED);

    aen AE_numstr(const char* s) {
        return FR_numstr(s, ALICE_ENGINE_DEFAULT_RADIX);
    }

    aen AE_mul(aen x, aen y) {
        return ((aenl)x * y) >> ALICE_ENGINE_DEFAULT_RADIX;
    }

    aen AE_div(aen x, aen y) {
        return FR_div_rnd((aenl)(x) << ALICE_ENGINE_DEFAULT_RADIX, y);
    }

    aen AE_pow2(aen x) {
        return FR_pow2(x, ALICE_ENGINE_DEFAULT_RADIX);
    }

    aen AE_log2(aen x) {
        return FR_log2(x, ALICE_ENGINE_DEFAULT_RADIX, ALICE_ENGINE_DEFAULT_RADIX);
    }

    aen AE_pow(aen base, aen expo) {
        return AE_pow2(AE_mul(expo, AE_log2(base)));
    }

    aen AE_rand() {
        return ae_generator();
    }
}