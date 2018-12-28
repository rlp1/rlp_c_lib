#include <mem.h>
#include <stdio.h>
#include <malloc.h>

#include "rlp_lib_string.h"

char* strcpy_range(const char *src, const size_t s_index, const size_t e_index) {
    const size_t len = strlen(src);
    char *buffer = (char *) malloc(sizeof(char) * (e_index - s_index) + 2);
    size_t buffer_pos = 0;
    for (size_t pos = s_index; pos <= e_index; pos++, buffer_pos++) {
        *(buffer + buffer_pos) = *(src + pos);
    }
    // @Note Every string in "C" must be '\0' in the last index of the character array.
    *(buffer + buffer_pos) = '\0';
    return buffer;
}

char** strsplit(const char *src, const char token) {
    if (src == NULL) {
        return NULL;
    }

    char **split = (char **) malloc(1);
    const size_t len = strlen(src);

    size_t split_pos = 0;
    size_t last_token_pos = 0;

    for (size_t pos = 0; pos < len; pos++) {
        // @Note This represents the current char of the source string.
        const char current_char = *(src + pos);

        if (current_char == token || pos == len - 1) {
            *(split + split_pos) = strcpy_range(src, last_token_pos, pos == len - 1 ? pos : pos - 1);

            // @Note The last token position is set to "pos + 1", because is must jump the token character.
            //      -rlp, 28 December 2018
            last_token_pos = pos + 1;
            split_pos++;
        }
    }

    return split;
}