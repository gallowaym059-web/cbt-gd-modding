#include "../features/click_before_tick.hpp"
#include <geode/Geode.hpp>

using namespace geode::prelude;

namespace ClickBeforeTick {
    void init() {
        log::info("Initializing click-before-tick...");
    }

    void processInput() {
        // Process queued inputs before the tick
    }
}
