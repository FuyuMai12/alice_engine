#include <cassert>
#include <map>

#include "chara.h"
#include "elements.h"
#include "action_queue.h"
#include "combat_logics.h"

namespace alice_engine {
    class CombatCharacterMetadata: public std::pair<bool, Coordinates2D> {
    public:
        bool& is_enemy = this->first;
        Coordinates2D& coordinates = this->second;
        using pair::pair;
    };

    enum EngineState {
        NOT_STARTED,
        RUNNING,
        ENDED
    };

    class CombatEngine {
    private:
        ActionQueue _queue;
        std::map<Character, CombatCharacterMetadata> _characters;
        EngineState _state;
    public:
        CombatEngine() {
            _state = NOT_STARTED;
        }

        void addCharacter(Character& chara, bool is_enemy, Coordinates2D& coordinates) {
            assert (_state == NOT_STARTED);
            assert (_characters.find(chara) == _characters.end());
            _characters.insert({chara, CombatCharacterMetadata(is_enemy, coordinates)});
        }

        void start() {
            assert (_state == NOT_STARTED);
        }

        void tick() {
            assert (_state == RUNNING);
        }
    };
}