#include <stdio.h>

#include "smallest_char.h"

int main() {
	char input1[] = "abcdefghijklmnopqrstuvwxyz";

	printf( "%c\n", smallest_character( input1, '\0' ) );

	return 0;
}
