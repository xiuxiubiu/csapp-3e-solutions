#include <assert.h>

int int_shifts_are_arthmetic() {
    char x = 0;
    return !~((~x) >> sizeof(char));
}

int new_int_shifts_are_arthmetic() {
    char x = -1;
    return !((x >> 1) ^ x);
}

int main() {
    assert(int_shifts_are_arthmetic());
    assert(new_int_shifts_are_arthmetic());
    return 0;
}