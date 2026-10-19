#include "ae_core.h"
#include "action.h"
using namespace ae_core;

#include <queue>

class TimestampedAction: public std::pair<aen, Action*> {
public:
    aen& timestamp = this->first;
    Action*& action = this->second;
};

class ActionQueue: public std::priority_queue<TimestampedAction,
                                              std::greater<TimestampedAction>,
                                              std::vector<TimestampedAction>> {

};
