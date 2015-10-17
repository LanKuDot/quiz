#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "max_sub_array.h"

int main( int argc, char *argv[] )
{
	assert( argc == 3 && "Input format: <program> <length> <range:-k~+k>" );
	assert( atoi( argv[2] ) > 0 && "Range K must be positive" );

	int numbers[ atoi(argv[1]) ], length = atoi( argv[1] ), range = atoi( argv[2] );

	srand( time(NULL) );

	printf( "Input array:" );
	for ( int i = 0; i < length; ++i ) {
		numbers[i] = ( rand() % ( (range << 1) + 1 ) ) - range;
		printf( " %d", numbers[i] );
	}
	printf( "\n" );
	printf( "Max subarray sum: %d\n", maxSubArray( numbers, length ) );

	return 0;
}
