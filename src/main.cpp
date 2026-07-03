#include <Geode/Geode.hpp>
#include <hjfod.gmd-api/include/GMD.hpp>
#include <camila314.drag-drop/include/DragDrop.hpp>
#include <miskaa.notif/src/include/notifapi.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        
        static bool hasSetUp = false;
        if (!hasSetUp) {
            hasSetUp = true;
            handleDragDrop({ "gmd" }, [](ghc::filesystem::path path) {
                auto result = gmd::importGmdAsLevel(path);
                if (result.isOk()) {
                    notifapi::success("Imported .gmd file!");
                } else {
                    notifapi::error("Failed to import .gmd somehow");
                }
            });
        }
        
        return true;
    }
};
