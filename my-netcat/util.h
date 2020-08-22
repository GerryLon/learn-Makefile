#ifndef __UTIL_H
#define __UTIL_H

#include "defs.h"

BOOL my_is_space(char c);


/*
 * get length of s
 */
int my_strlen(const char *s);

// 会修改s
char *my_str_trim(char *s);

int my_str_cmp(const char *s1, const char *s2);
#endif
