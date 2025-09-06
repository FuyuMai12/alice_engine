#pragma once

#include "combat_logics.h"

class Element {
private:
    Element*  _counteredBy;
    Element*  _countering ;
    __int64_t  _counteredRatio;
    __int64_t _counteringRatio;
public:
    /**
    * @brief Initialize an element.
    */
    Element() {
        this->_counteredRatio  = combat_logics::ONE *  80 / 100;
        this->_counteringRatio = combat_logics::ONE * 125 / 100;
    }

    /**
    * @brief Set an element that counters the current element.
    *
    * @param counteredElement The element that counters the current element.
    * @param counteredRatio The ratio of decreasing damage taken by the countered element.
    * This should be a value lower than combat_logics::ONE.
    * -1 denotes using the default/current value.
    *
    * @returns None.
    */
    void setCounteredBy(Element &counteredElement, __int64_t counteredRatio = -1LL) {
        this->_counteredBy = counteredElement;
        if (counteredRatio != -1LL) this->_counteredRatio = counteredRatio;
    }

    /**
    * @brief Set an element that is countered by the current element.
    *
    * @param counteredElement The element that is countered by the current element.
    * @param counteredRatio The ratio of increasing damage taken by the countering element.
    * This should be a value higher than combat_logics::ONE.
    * -1 denotes using the default/current value.
    *
    * @returns None.
    */
    void setCountering(Element &counteringElement, __int64_t counteringRatio = -1LL) {
        this->_countering = counteringElement;
        if (counteringRatio != -1LL) this->_counteringRatio = counteringRatio;
    }
};

namespace default_elements {
    // Neutral element: counters nothing, nothing counters it.
    Element NEUTRAL   = Element();

    // Pentagon of basic elements: FIRE, AIR, LIGHTNING, EARTH and WATER.
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
