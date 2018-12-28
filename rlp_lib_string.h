#ifndef RLP_LIB_RLP_LIB_STRING_H
#define RLP_LIB_RLP_LIB_STRING_H

/* This method copy a range of character from source string. This represents a way to fix the occured
 * with the "memcpy" that doesn't has a range to copy the memory.
 *
 * src -> this represents the source string that will be copied.
 * s_index -> this represents the start index.
 * e_index -> this represents the end index.
 * */
char* strcpy_range(const char *src, const size_t s_index, const size_t e_index);

/* This function split the string in parts between the "token".
 *
 * src -> this represents the string that will be split.
 * token -> this represents the token that will be checked in the string to be split.
 * */
char** strsplit(const char *src, const char token);

#endif //RLP_LIB_RLP_LIB_STRING_H
