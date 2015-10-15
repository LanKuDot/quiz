#include "smallest_char.h"

char smallest_character( char str[], char c )
{
	const char *strptr = str;

	if ( c == '\0' )
		return str[0];

	while( *strptr != '\0' ) {
		if ( *strptr > c )
			return *strptr;
		++strptr;
	}
	return str[0];
}
