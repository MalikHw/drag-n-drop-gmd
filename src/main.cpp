#include <Geode/Geode.hpp>
#include <hjfod.gmd-api/include/GMD.hpp>
#include <camila314.drag-drop/include/DragDrop.hpp>
#include <miskaa.notif/src/includes/notif.hpp>

using namespace geode::prelude;

$on_mod(Loaded) {
    DragDropEvent(DragDropType::Drop).listen([](std::filesystem::path const& path) -> bool {
        if (path.extension() == ".gmd" || path.extension() == ".GMD") {
            auto level = gmd::importGmdAsLevel(path);
            if (level) {
                notifapi::success("Imported .gmd file!");
            } else {
                notifapi::error("Failed to import .gmd somehow");
            }
        }
        return true;
    }).leak();
}
