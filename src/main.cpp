#include <geode/Geode.hpp>
#include "hooks/game_loop.hpp"
#include "features/click_before_tick.hpp"
#include "features/tps_bypass.hpp"

using namespace geode::prelude;

class CBTMod : public Geode::Mod {
public:
    static CBTMod* get() {
        static auto inst = new CBTMod();
        return inst;
    }

    bool cbtEnabled() const {
        return Mod::get()->getSettingValue<bool>("cbt-enabled");
    }

    bool safeMode() const {
        return Mod::get()->getSettingValue<bool>("safe-mode");
    }

    float tpsMultiplier() const {
        return Mod::get()->getSettingValue<float>("tps-multiplier");
    }

    bool isActive() const {
        if (safeMode()) {
            return true;
        }
        return true;
    }
};

$on_mod(Loaded) {
    log::info("Click Before Tick mod loaded!");
    GameLoopHooks::init();
    ClickBeforeTick::init();
    TPSBypass::init();
}

GEODE_API bool GEODE_CALL geode_implicit_load(geode::Mod*) {
    return true;
}
