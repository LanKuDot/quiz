#include <assert.h>
#include <stdio.h>

#include "smallest_char.h"

int main( int argc, char *argv[] )
{
	/* There must be 3 arguments. */
	assert( argc == 3 && "Input format: <program> <sorted_str> <search character>" );

	printf( "%c\n", smallest_character( argv[1], argv[2][0] ) );

	return 0;
}
