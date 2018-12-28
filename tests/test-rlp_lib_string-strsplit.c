#include <stdio.h>
#include "../rlp_lib_string.h"

int main() {
    char **buffer = strsplit("test-token-test123", '-');

    printf("buffer[0]: %s\n", buffer[0]);
    printf("buffer[1]: %s\n", buffer[1]);
    printf("buffer[2]: %s\n", buffer[2]);

    free(buffer);
    return 0;
}