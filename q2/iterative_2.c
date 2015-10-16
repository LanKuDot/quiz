#include <stdio.h>
#include <string.h>

#include "smallest_char.h"

char smallest_character( char str[], char c )
{
	int left = 0, right = strlen(str) - 1, center;

	if ( c == '\0' )
		return str[0];
	if ( right < 0 )
		return '\0';

	while ( left != right ) {
		center = ( left + right ) >> 1;
		if ( str[center] > c )
			right = --center;
		else
			left = ++center;
	}

	if ( str[left] > c )
		return str[left];
	else if ( str[left+1] != '\0' )
		return str[left+1];
	else
		return str[0];
}
