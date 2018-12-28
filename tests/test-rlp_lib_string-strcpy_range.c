#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../rlp_lib_string.h"

int main() {
    char *src = "Test, test...";
    char *new_src = strcpy_range(src, 1, 4); // Copied string will be: "est,"

    assert(strcmp(new_src, "est,") == 0);

    free(src);
    free(new_src);
    return 0;
}