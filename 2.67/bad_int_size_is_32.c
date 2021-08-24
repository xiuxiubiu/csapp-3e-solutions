#include <assert.h>

int int_size_is_32() {
    int set_msb = 1 << 15 << 15 << 1;
    return set_msb && !(set_msb << 1);
}

int main() {
    assert(int_size_is_32() == 1);
    return 0;
}