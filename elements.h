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

    void setCounteredBy(Element &counteredElement, __int64_t counteredRatio) {
        this->_counteredBy = counteredElement;
        this->_counteredRatio = counteredRatio;
    }

    void setCountering(Element &counteringElement, __int64_t counteringRatio) {
        this->_countering = counteringElement;
        this->_counteringRatio = counteringRatio;
    }
};

class ElementNeutral: Element {
    ElementNeutral(): Element() {}
};
