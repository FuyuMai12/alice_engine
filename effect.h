#include <cassert>
#include <map>

#include "ae_core.h"
#include "string.h"
using namespace ae_core;

enum EffectType {
    MAX_HP_FLAT, MAX_HP_RATIO,
    MAX_MP_FLAT, MAX_MP_RATIO,
    ATK_FLAT, ATK_RATIO,
    DEF_FLAT, DEF_RATIO,
    TEC_FLAT, TEC_RATIO,
    MEN_FLAT, MEN_RATIO,
    AGI_FLAT, AGI_RATIO,
    LUC_FLAT, LUC_RATIO,
    POSITIVE_HP_SENT_FLAT, POSITIVE_HP_SENT_RATIO,
    POSITIVE_HP_RECEIVED_FLAT, POSITIVE_HP_RECEIVED_RATIO,
    NEGATIVE_HP_SENT_FLAT, NEGATIVE_HP_SENT_RATIO,
    NEGATIVE_HP_RECEIVED_FLAT, NEGATIVE_HP_RECEIVED_RATIO,
    POSITIVE_MP_SENT_FLAT, POSITIVE_MP_SENT_RATIO,
    POSITIVE_MP_RECEIVED_FLAT, POSITIVE_MP_RECEIVED_RATIO,
    NEGATIVE_MP_SENT_FLAT, NEGATIVE_MP_SENT_RATIO,
    NEGATIVE_MP_RECEIVED_FLAT, NEGATIVE_MP_RECEIVED_RATIO,
};

class Effect {
private:
    char* _name;
    char* _desc;
    int _max_stack;
    aenl _mask;
    std::map<EffectType, aen> _modifiers;
public:
    Effect(char* __name, char* __desc, int __max_stack, int __stack_mask_bit_id = -1) {
        assert((0 <= __stack_mask_bit_id && __stack_mask_bit_id > __max_stack));
        this->_mask = (aenl)(1) << __stack_mask_bit_id;

        this->_max_stack = __max_stack;
        strcpy(this->_name, __name);
        strcpy(this->_desc, __desc);
    }
};