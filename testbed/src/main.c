#include <core/logger.h>
#include <core/asserts.h>

int main(void) {
    KFATAL("A test massege: %f", 3.14f);
    KERROR("A test massege: %f", 3.14f);
    KWARN("A test massege: %f", 3.14f);
    KINFO("A test massege: %f", 3.14f);
    KTRACE("A test massege: %f", 3.14f);

    KASSERT(1 == 0);
    return 0;
}