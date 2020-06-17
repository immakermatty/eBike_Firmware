#ifdef ESP32

#include "ebikeUpdate.h"

namespace ebike {

namespace Update {

    void start()
    {
        AccessPointWebUpdate::start("EBIKE_UPDATE", nullptr, "update");
    }

}
}

#endif