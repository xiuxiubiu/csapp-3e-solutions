#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void copy_int(int val, void *buf, int maxbytes) {
    /**
     * sizeof返回size_t类型
    */
    // if (maxbytes - sizeof(val) >= 0)
    if (maxbytes - (int) sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}
