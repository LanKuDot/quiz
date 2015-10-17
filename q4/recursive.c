/* Use divide and conquer.
 * Find the max subarray in left half,
 * and then find the max subarray in right half.
 * Finally, find the max subarray from the center.
 */
#include <stdio.h>

#include "max_sub_array.h"

#define MAX(a, b) (((a)>(b))?(a):(b))

int maxSubArrayHalf( int A[], int l, int r );
int maxSubArrayCenter( int A[], int l, int c, int r );

int maxSubArray( int A[], int n )
{
	if ( A == NULL )
		return 0;
	if ( n == 0 )
		return 0;
	if ( n == 1 )
		return A[0];

	return maxSubArrayHalf( A, 0, n-1 );
}

int maxSubArrayHalf( int A[], int l, int r )
{
	if ( l == r )
		return A[l];

	int center = ( l + r ) >> 1;

	return MAX( MAX( maxSubArrayHalf( A, l, center ),
			maxSubArrayHalf( A, center+1, r ) ),
			maxSubArrayCenter( A, l, center, r ) );
}

int maxSubArrayCenter( int A[], int l, int c, int r )
{
	int max_left = 0, max_right = 0, localMax = 0;

	for ( int i = c; i >= l; --i ) {
		localMax = localMax + A[i];
		max_left = MAX( max_left, localMax );
	}

	localMax = 0;
	for ( int i = c + 1; i <= r; ++i ) {
		localMax = localMax + A[i];
		max_right = MAX( max_right, localMax );
	}

	return max_left + max_right;
}
