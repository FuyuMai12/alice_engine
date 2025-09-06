#pragma once

#include "combat_logics.h"

class Element {
private:
    Element*  _counteredBy;
    Element*  _countering ;
    __int64_t  _counteredRatio;
    __int64_t _counteringRatio;
public:
    Element() {
        this->_counteredRatio  = combat_logics::ONE *  80 / 100;
        this->_counteringRatio = combat_logics::ONE * 125 / 100;
    }

    void setCounteredBy(Element &counteredElement, __int64_t counteredRatio = -1LL) {
        this->_counteredBy = counteredElement;
        if (counteredRatio != -1LL) this->_counteredRatio = counteredRatio;
    }

    void setCountering(Element &counteringElement, __int64_t counteringRatio = -1LL) {
        this->_countering = counteringElement;
        if (counteringRatio != -1LL) this->_counteringRatio = counteringRatio;
    }
};

namespace default_elements {
    Element NEUTRAL   = Element();
    Element FIRE      = Element();
    Element AIR       = Element();
    Element LIGHTNING = Element();
    Element EARTH     = Element();
    Element WATER     = Element();

    FIRE.setCounteredBy(WATER);
    FIRE.setCountering(AIR);

    AIR.setCounteredBy(FIRE);
    AIR.setCountering(LIGHTNING);

    LIGHTNING.setCounteredBy(AIR);
    LIGHTNING.setCountering(EARTH);

    EARTH.setCounteredBy(LIGHTNING);
    EARTH.setCountering(WATER);

    WATER.setCounteredBy(EARTH);
    WATER.setCountering(FIRE);
}
