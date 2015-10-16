#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( int argc, char *argv[] )
{
	char charBank[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char str[53+1];    // 1 for null character.
	int len = 0;

	srand( time(NULL) );
	for ( int i = 0; i < 53; ++i ) {
		if ( rand() & 1 )
			str[len++] = charBank[i];
	}
	str[len] = '\0';

	printf( "%s %c\n", str, charBank[ rand() % 52 ] );

	return 0;
}
