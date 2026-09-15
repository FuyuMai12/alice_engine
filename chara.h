#pragma once

#include "elements.h"
#include "string.h"
using namespace ae_core;

/**
* @brief The most basic agent in a game: a character. Can be either a PC or an NPC.
*
* @param _hp, _mp Character's max HP and MP, respectively.
* @param _atk, _def Character's physical offensive and defensive power, respectively.
* @param _tec, _men Character's magical offensive and defensive power, respectively.
* @param _agi Character's speed.
* @param _luc Character's luck/luckiness.
* @param _name Character's name
* @param _element An Element object that denotes the character's element
* @param _curr_hp, _curr_mp Character's current HP and MP, respectively.
*/
class Character {
private:
    aen _hp;
    aen _mp;
    aen _atk;
    aen _def;
    aen _tec;
    aen _men;
    aen _agi;
    aen _luc;
    char* _name;
    Element* _element;
    aen _curr_hp;
    aen _curr_mp;
public:
    const aen MAX_DISPLAY_HP  = AE_numstr("9999");
    const aen MAX_DISPLAY_MP  = AE_numstr("9999");
    const aen MAX_DISPLAY_ATK = AE_numstr( "999");
    const aen MAX_DISPLAY_DEF = AE_numstr( "999");
    const aen MAX_DISPLAY_TEC = AE_numstr( "999");
    const aen MAX_DISPLAY_MEN = AE_numstr( "999");
    const aen MAX_DISPLAY_AGI = AE_numstr( "999");
    const aen MAX_DISPLAY_LUC = AE_numstr( "999");

    /**
    * @brief Initialize a character.
    *
    * @param __name Character's name
    * @param __elem An Element object that denotes the character's element
    * @param __hp, __mp Character's max HP and MP, respectively. This is also used
    * to initialize a character's current HP and MP as well.
    * @param __atk, __def Character's physical offensive and defensive power, respectively.
    * @param __tec, __men Character's magical offensive and defensive power, respectively.
    * @param __agi Character's speed.
    * @param __luc Character's luck/luckiness.
    */
    Character(char* __name, Element& __elem,
              aen __hp , aen __mp,
              aen __atk, aen __def,
              aen __tec, aen __men,
              aen __agi, aen __luc) {
        strcpy(this->_name, __name);
        _element = &__elem;

        this->_hp  = __hp ; this->_mp  = __mp ;
        this->_atk = __atk; this->_def = __def; this->_tec = __tec;
        this->_men = __men; this->_agi = __agi; this->_luc = __luc;
        
        this->_curr_hp = this->_hp; this->_curr_mp = this->_mp;
    }
};