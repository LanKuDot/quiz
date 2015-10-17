#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "max_sub_array.h"
#include "../diff_in_second.h"

int main( int argc, char *argv[] )
{
	assert( argc == 3 && "Input format: <program> <length> <range:-k~+k>" );
	assert( atoi( argv[2] ) > 0 && "Range K must be positive" );

	int numbers[ atoi(argv[1]) ], length = atoi( argv[1] ), range = atoi( argv[2] ), max;
	struct timespec start, end;

	srand( time(NULL) );

	printf( "Input array:" );
	for ( int i = 0; i < length; ++i ) {
		numbers[i] = ( rand() % ( (range << 1) + 1 ) ) - range;
		printf( " %d", numbers[i] );
	}
	printf( "\n" );

	/* Measure execution time */
	clock_gettime( CLOCK_REALTIME, &start );
	max = maxSubArray( numbers, length );
	clock_gettime( CLOCK_REALTIME, &end );
	printf( "Execution time: %.9lf sec.\n", diff_in_second( start, end ) );

	printf( "The max subarray sum is: %d\n", max );

	return 0;
}
