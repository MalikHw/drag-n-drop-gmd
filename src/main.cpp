#include <Geode/Geode.hpp>
#include <hjfod.gmd-api/include/GMD.hpp>
#include <camila314.drag-drop/include/DragDrop.hpp>
#include <miskaa.notif/src/includes/notif.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    DragDropEvent::subscribe([](DragDropEvent* event) {
        if (event->getType() == DragDropType::Drop) {
            auto path = event->getData();
            if (path.extension() == ".gmd" || path.extension() == ".GMD") {
                auto level = gmd::importGmdAsLevel(path);
                if (level) {
                    notifapi::success("Imported gmd!");
                } else {
                    notifapi::error("Failed to import for some reason");
                }
            }
        }
    });
}
