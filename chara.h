#pragma once

#include "elements.h"

class Character {
private:
    __int16_t _hp;
    __int16_t _mp;
    __int16_t _atk;
    __int16_t _def;
    __int16_t _tec;
    __int16_t _men;
    __int16_t _agi;
    __int16_t _luc;
    char* _name;
    Element* _element;
    __int16_t _curr_hp;
    __int16_t _curr_mp;
public:
    const __int16_t MAX_DISPLAY_HP  = 9999;
    const __int16_t MAX_DISPLAY_MP  = 9999;
    const __int16_t MAX_DISPLAY_ATK =  999;
    const __int16_t MAX_DISPLAY_DEF =  999;
    const __int16_t MAX_DISPLAY_TEC =  999;
    const __int16_t MAX_DISPLAY_MEN =  999;
    const __int16_t MAX_DISPLAY_AGI =  999;
    const __int16_t MAX_DISPLAY_LUC =  999;

    /**
    * @brief Initialize a character.
    *
    * This function initializes a character with basic required attributes.
    *
    * @param __name Character name
    * @param __elem Character's element
    * @param __hp, __mp Character's max HP and MP, respectively. This is also used
    * to initialize a character's current HP and MP as well.
    * @param __atk, __def Character's physical offensive and defensive power, respectively.
    * @param __tec, __men Character's magical offensive and defensive power, respectively.
    * @param __agi Character's speed.
    * @param __luc Character's luck/luckiness.
    */
    Character(char* __name, Element& __elem,
              __int16_t __hp , __int16_t __mp,
              __int16_t __atk, __int16_t __def,
              __int16_t __tec, __int16_t __men,
              __int16_t __agi, __int16_t __luc,) {
        strcpy(this->_name, __name);
        _element = __elem;

        this->_hp  = __hp ; this->_mp  = __mp ;
        this->_atk = __atk; this->_def = __def; this->_tec = __tec;
        this->_men = __men; this->_agi = __agi; this->_luc = __luc;
        
        this->_curr_hp = this->_hp; this->_curr_mp = this->_mp;
    }
};