#include <stddef.h>

void* another_colloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    size_t buf_size = nmemb * size;
    if (nmemb == buf_size/size) {

    }
    return NULL;
}