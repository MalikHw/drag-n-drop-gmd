#include <Geode/Geode.hpp>
#include <hjfod.gmd-api/include/GMD.hpp>
#include <camila314.drag-drop/include/DragDrop.hpp>
#include <miskaa.notif/src/includes/notif.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    static EventListener<DragDropEvent> listener;
    listener.setFilter(DragDropType::Drop);
    listener.bind([](std::filesystem::path const& path) {
        if (path.extension() == ".gmd" || path.extension() == ".GMD") {
            auto level = gmd::importGmdAsLevel(path);
            if (level) {
                notifapi::success("Imported .gmd file!");
            } else {
                notifapi::error("Failed to import .gmd somehow");
            }
        }
    });
}
