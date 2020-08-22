#include "util.h"

BOOL my_is_space(char c) {
	return (c == ' ' || c == '\t' || c == '\n') ? TRUE : FALSE;
}


int my_strlen(const char *s) {
	char *p = (char *)s;
	int len = 0;

	for (; *p; p++, len++);

	return len;
}

// 得到的是原串的一个子串的起始指针
char *my_str_trim(char *str) {
   char *end;
    /* skip leading whitespace */
    while (my_is_space(*str)) {
        str = str + 1;
    }
    /* remove trailing whitespace */
    end = str + my_strlen(str) - 1;
    while (end > str && my_is_space(*end)) {
        end = end - 1;
    }
    /* write null character */
    *(end + 1) = '\0';
    return str;
}

// s1 > s2  => 正
// s1 < s2  => 负
// s1 == s2 => 0
int my_str_cmp(const char *s1, const char *s2) {
	char *p1 = (char*)s1;
	char *p2 = (char*)s2;

	if (!p1 && !p2) {
		return 0;
	}
	if (!p1) {
		return -1;
	}
	if (!p2) {
		return 1;
	}

	for (; *p1 && *p2 && *p1 == *p2; p1++, p2++);

	return (int)*p1 - (int)*p2;
}
