#include "chara.h"
using namespace ae_core;

enum ActionType {
    ENTRY,
    READY,
    SEND,
    RECEIVE
};

class Action {
private:
    Character* chara;
    ActionType atype;
};