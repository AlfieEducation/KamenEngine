#include <core/logger.h>
#include <core/asserts.h>

// TODO: Just test of new platform realization
#include <platform/platform.h>

int main(void) {
    KFATAL("A test massege: %f", 3.14f);
    KERROR("A test massege: %f", 3.14f);
    KWARN("A test massege: %f", 3.14f);
    KINFO("A test massege: %f", 3.14f);
    KTRACE("A test massege: %f", 3.14f);

    platform_state state; 
    if (platform_startup(&state, "Kamen Engine Sandbox", 150, 150, 1280, 720)) {
        while (true) {
            platform_pump_messages(&state);
        }
    }
    platform_shutdown(&state);
    return 0;
}