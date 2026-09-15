#pragma once

#include "combat_logics.h"
using namespace ae_core;

/**
* @brief An element. Different elements will have different damage interactions and buffs/debuffs.
*
* @param _counteredBy An Element object that denotes the element that counters the current element.
* @param _countering An Element object that denotes the element that is countered by the current element.
* @param _counteredRatio The ratio of decreasing damage taken by the countered element.
* This should be a value lower than 1.
* @param _counteringRatio The ratio of increasing damage taken by the countering element.
* This should be a value higher than 1.
*/
class Element {
private:
    Element* _counteredBy;
    Element* _countering ;
    aen  _counteredRatio;
    aen _counteringRatio;
public:
    /**
    * @brief Initialize an element.
    */
    Element() {
        this->_counteredRatio  = AE_numstr("0.8");
        this->_counteringRatio = AE_numstr("1.25");
    }

    /**
    * @brief Set an element that counters the current element.
    *
    * @param counteredElement An Element object that denotes the element that counters the current element.
    * @param counteredRatio The ratio of decreasing damage taken by the countered element.
    * This should be a value lower than 1.
    * -1 denotes using the default/current value.
    *
    * @returns None.
    */
    void setCounteredBy(Element &counteredElement, aen counteredRatio = AE_numstr("-1")) {
        this->_counteredBy = &counteredElement;
        if (counteredRatio != AE_numstr("-1")) this->_counteredRatio = counteredRatio;
    }

    /**
    * @brief Set an element that is countered by the current element.
    *
    * @param counteredElement An Element object that denotes the element that is countered by the current element.
    * @param counteredRatio The ratio of increasing damage taken by the countering element.
    * This should be a value higher than 1.
    * -1 denotes using the default/current value.
    *
    * @returns None.
    */
    void setCountering(Element &counteringElement, aen counteringRatio = AE_numstr("-1")) {
        this->_countering = &counteringElement;
        if (counteringRatio != AE_numstr("-1")) this->_counteringRatio = counteringRatio;
    }
};

namespace default_elements {
    // Initialization state of the default elements. If not initialized, this can't be used.
    bool initialized = false;

    // Neutral element: counters nothing, nothing counters it.
    Element NEUTRAL   = Element();

    // Pentagon of basic elements: FIRE, AIR, LIGHTNING, EARTH and WATER.
    Element FIRE      = Element();
    Element AIR       = Element();
    Element LIGHTNING = Element();
    Element EARTH     = Element();
    Element WATER     = Element();

    void initialize() {
        initialized = true;

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
}
