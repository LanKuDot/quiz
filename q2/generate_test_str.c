#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* argv[1]: the times of each character decided.
 */
int main( int argc, char *argv[] )
{
	char charBank[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char str[52 * atoi(argv[1]) + 1];    // 1 for null character.
	int len = 0, times = atoi( argv[1] );

	srand( time(NULL) );
	for ( int i = 0; i < 52 * times + 1; ++i ) {
		if ( rand() & 1 )
			str[len++] = charBank[i/times];
	}
	str[len] = '\0';

	printf( "%s %c\n", str, charBank[ rand() % 52 ] );

	return 0;
}
