#include <stdio.h>
#include <stdlib.h> // for atoi()

#define PI 3.14

int main(int argc, char **argv) {
	int sum = 0;
	int i = 0;
	printf("pi: %.2f", PI); 
	for (; i < argc; i++) {
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
}
