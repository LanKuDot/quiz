#include "smallest_char.h"

#include <string.h>

char smallest_character_rev( const char* str, int left, int right, char c );

char smallest_character( char str[], char c )
{
	int left = 0, right = strlen(str) - 1;

	if ( c == '\0' )
		return str[0];
	if ( right < 0 )
		return '\0';

    return smallest_character_rev( str, left, right, c );
}

char smallest_character_rev( const char *str, int left, int right, char c )
{
	int center = ( left + right ) >> 1, _left = left, _right = right;

	if ( str[center] > c )
		_right = --center;
	else
		_left = ++center;

	if ( !( _left < _right ) ) {
		if ( str[_left] > c )
			return str[_left];
		else if ( str[_left+1] != '\0' )
			return str[_left+1];
		else
			return str[0];
	}

	return smallest_character_rev( str, _left, _right, c );
}
