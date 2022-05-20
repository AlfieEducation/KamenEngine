#include <core/logger.h>

int main(void) {
    KFATAL("A test massege: %f", 3.14f);
    KERROR("A test massege: %f", 3.14f);
    KWARN("A test massege: %f", 3.14f);
    KINFO("A test massege: %f", 3.14f);
    KTRACE("A test massege: %f", 3.14f);
    return 0;
}