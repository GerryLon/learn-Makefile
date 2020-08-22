#include <assert.h>


#include "util.h"

int main(void) {
	assert(my_strlen("") == 0);
	assert(my_strlen("hello world") == 11);

	assert(my_str_cmp("", "") == 0);
	assert(my_str_cmp("a", "a") == 0);
	assert(my_str_cmp("a", "b") < 0);
	assert(my_str_cmp("b", "a") > 0);

	char str[] = "    a  ";
	assert(my_str_cmp(my_str_trim(str), "a") == 0);
	return 0;
}
