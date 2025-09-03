#pragma once

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
public:
    const __int16_t MAX_DISPLAY_HP  = 9999;
    const __int16_t MAX_DISPLAY_MP  = 9999;
    const __int16_t MAX_DISPLAY_ATK =  999;
    const __int16_t MAX_DISPLAY_DEF =  999;
    const __int16_t MAX_DISPLAY_TEC =  999;
    const __int16_t MAX_DISPLAY_MEN =  999;
    const __int16_t MAX_DISPLAY_AGI =  999;
    const __int16_t MAX_DISPLAY_LUC =  999;

    Character(char* __name,
              __int16_t __hp , __int16_t __mp,
              __int16_t __atk, __int16_t __def,
              __int16_t __tec, __int16_t __men,
              __int16_t __agi, __int16_t __luc,) {
        strcpy(_name, __name);
        _hp  = __hp ; _mp  = __mp ;
        _atk = __atk; _def = __def; _tec = __tec;
        _men = __men; _agi = __agi; _luc = __luc;
    }
};