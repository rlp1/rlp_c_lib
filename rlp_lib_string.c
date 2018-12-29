#include <mem.h>
#include <stdio.h>
#include <malloc.h>

#include "rlp_lib_string.h"

char*
strcpy_range(const char *src, const size_t s_index, const size_t e_index) 
{
    const size_t len = strlen(src);
    char *buffer = (char *) malloc(sizeof(char) * (e_index - s_index) + 2);
    size_t buffer_pos = 0;
    for (size_t pos = s_index; pos <= e_index; pos++, buffer_pos++) 
    {
        *(buffer + buffer_pos) = *(src + pos);
    }
    // @Note Every string in "C" must be '\0' in the last index of the character array.
    *(buffer + buffer_pos) = '\0';
    return buffer;
}

char** 
strsplit(char *str, const char *token)
{
    char *current_token = strtok(str, token);
    size_t tok_pos = 0;

    char **buffer = NULL;

    while (current_token != NULL)
    {
        // @Note Check if the buffer is null, then allocate a memory
        // to the buffer.
        if (buffer == NULL)
        {
            // @Note Allocate 1 byte size to the buffer,
            // and in the next opertaions re-allocate it.
            buffer = (char **) malloc(1);
        }
        
        // @Note The "memcpy" function token length is represented by the all characters
        // that contains in the token string plus 1, this one represents the every last
        // character that contains in the every string that is represented by '\0'.
        //      -rlp, 29 December 2018.
        const size_t memcpy_token_length = strlen(current_token) + 1;

        *(buffer + tok_pos) = (char *) malloc(memcpy_token_length);
        memcpy(*(buffer + tok_pos), current_token, memcpy_token_length);

        printf("%s\n", *(buffer + tok_pos));

        current_token = strtok(NULL, token);
        tok_pos++;
    }

    return buffer;
}

int
isascii_string(const char *str)
{
    while (*str) if (!isascii(*str++)) return 1;
    return 0;
}

//
// ... Deprecated functions ...
//

/* This function to split strings is deprecated. */
char** 
_____strsplit(const char *src, const char token) 
{
    if (src == NULL) 
    {
        return NULL;
    }

    char **split = (char **) malloc(1);
    const size_t len = strlen(src);

    size_t split_pos = 0;
    size_t last_token_pos = 0;

    for (size_t pos = 0; pos < len; pos++) 
    {
        // @Note This represents the current char of the source string.
        const char current_char = *(src + pos);

        if (current_char == token || pos == len - 1) 
        {
            *(split + split_pos) = strcpy_range(src, last_token_pos, pos == len - 1 ? pos : pos - 1);

            // @Note The last token position is set to "pos + 1", because is must jump the token character.
            //      -rlp, 28 December 2018
            last_token_pos = pos + 1;
            split_pos++;
        }
    }

    return split;
}