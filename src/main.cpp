#include <Geode/Geode.hpp>
#include <hjfod.gmd-api/include/GMD.hpp>
#include <camila314.drag-drop/include/DragDrop.hpp>
#include <miskaa.notif/src/includes/notif.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    handleDragDrop({ "gmd" }, [](auto path) {
        auto level = gmd::importGmdAsLevel(path);
        if (level) {
            notifapi::success("Imported!");
        } else {
            notifapi::error("Failed!");
        }
    });
}