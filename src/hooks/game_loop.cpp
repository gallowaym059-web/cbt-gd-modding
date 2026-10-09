#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>
#include "config.hpp"

using namespace geode::prelude;

class $modify(CBTBaseGameLayer, GJBaseGameLayer) {
    void update(float dt) {
        if (dt > 0.f && cbt::featuresAllowed(this)) {
            dt *= static_cast<float>(cbt::tpsMultiplier());
        }
        GJBaseGameLayer::update(dt);
    }

    // TODO: click-before-tick. Needs a hook on the game's input path
    // (e.g. handleButton / processQueuedButtons) that timestamps presses
    // and applies them at the right physics sub-step. Gate it with
    // cbt::cbtEnabled() && cbt::featuresAllowed(this).
};
