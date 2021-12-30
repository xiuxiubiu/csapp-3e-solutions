#include <stdio.h>
#define BUF_SIZE 10

void good_echo() {
    char buf[BUF_SIZE];
    char *s;
    while (!feof(stdin)) {
        if ((s = fgets(buf, BUF_SIZE, stdin)) == NULL)
            break;
        fputs(s, stdout);
    }
}

int main() {
    good_echo();
    return 0;
}