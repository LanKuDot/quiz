#include <assert.h>
#include <stdio.h>
#include <time.h>

#include "smallest_char.h"

static double diff_in_second( struct timespec t1, struct timespec t2 )
{
	struct timespec diff;
	if ( t2.tv_nsec - t1.tv_nsec < 0 ) {
		diff.tv_sec = t2.tv_sec - t1.tv_sec - 1;
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
	} else {
		diff.tv_sec = t2.tv_sec - t1.tv_sec;
		diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
	}
	return ( diff.tv_sec + diff.tv_nsec / 1000000000.0 );
}

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
