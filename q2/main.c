#include <assert.h>
#include <stdio.h>
#include <time.h>

#include "smallest_char.h"
#ifdef MEASURE_TIME
	#include "../diff_in_second.h"
#endif

int main( int argc, char *argv[] )
{
	/* There must be 3 arguments. */
	assert( argc == 3 && "Input format: <program> <sorted_str> <search character>" );
	
#ifdef MEASURE_TIME
	struct timespec start, end;

	clock_gettime( CLOCK_REALTIME, &start );
	smallest_character( argv[1], argv[2][0] );
	clock_gettime( CLOCK_REALTIME, &end );
#endif

	printf( "%c\n", smallest_character( argv[1], argv[2][0] ) );
#ifdef MEASURE_TIME
	printf( "Time for smallest_character(): %.9lf sec\n", diff_in_second( start, end ) );
#endif

	return 0;
}
