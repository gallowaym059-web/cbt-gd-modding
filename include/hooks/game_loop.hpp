#include "../hooks/game_loop.hpp"
#include <geode/Geode.hpp>

using namespace geode::prelude;

namespace GameLoopHooks {
    void init() {
        log::info("Initializing game loop hooks...");
    }
}
