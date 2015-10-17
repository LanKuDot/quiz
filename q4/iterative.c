#include <stdio.h>

#include "max_sub_array.h"

int maxSubArray( int A[], int n )
{
	if ( A == NULL )
		return 0;
	if ( n == 0 )
		return 0;
	if ( n == 1 )
		return A[0];

	int localmax, max;
	localmax = max = A[0];

	for ( int i = 1; i < n; ++i ) {
		localmax = ( localmax + A[i] > 0 ) ? ( localmax + A[i] ) : 0;
		max = ( localmax > max ) ? localmax : max;
	}

	return max;
}
