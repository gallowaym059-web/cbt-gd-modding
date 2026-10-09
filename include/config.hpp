#pragma once
#include <Geode/Geode.hpp>
#include <algorithm>

namespace cbt {
    inline bool cbtEnabled() {
        return geode::Mod::get()->getSettingValue<bool>("cbt-enabled");
    }

    inline bool safeMode() {
        return geode::Mod::get()->getSettingValue<bool>("safe-mode");
    }

    // Geode float settings are read as double.
    inline double tpsMultiplier() {
        double v = geode::Mod::get()->getSettingValue<double>("tps-multiplier");
        return std::clamp(v, 0.5, 4.0);
    }

    // Mod features run if safe mode is off, or if the current context can't
    // affect online progress: editor, practice mode, or test mode.
    inline bool featuresAllowed(GJBaseGameLayer* layer) {
        if (!safeMode()) return true;
        if (!layer) return false;
        if (geode::cast::typeinfo_cast<LevelEditorLayer*>(layer)) return true;
        if (auto pl = geode::cast::typeinfo_cast<PlayLayer*>(layer)) {
            return pl->m_isPracticeMode || pl->m_isTestMode;
        }
        return false;
    }
}
