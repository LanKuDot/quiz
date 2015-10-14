#include "smallest_char.h"

char smallest_character( char str[], char c )
{
	const char *strptr = str;
	while( *strptr != '\0' ) {
		if ( *strptr > c )
			return *strptr;
		++strptr;
	}
	return str[0];
}
