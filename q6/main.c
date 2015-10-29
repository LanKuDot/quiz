#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "reverseBetween.h"

ListNode *buildList( int length );
void printList( ListNode *head );
void freeList( ListNode *head );

int main( int argc, char *argv[] )
{
	assert( ( argc == 4 ) && "Input format: <program> <list length> <m> <n>" );

	int length, m, n;
	length = atoi( argv[1] );
	m = atoi( argv[2] );
	n = atoi( argv[3] );

	assert( ( length > 0 ) && ( m > 0 ) && ( n > 0 ) && "length, m, and n are positive." );
	assert( ( n <= length ) && ( m <= n ) && "m <= n <= length" );

	ListNode* root = buildList( length );
	printList( root );
	freeList( root );
}

ListNode *buildList( int length )
{
	ListNode *new = NULL, *cur, *head;

	cur = head = (ListNode *) malloc( sizeof( ListNode ) );
	cur->data = 1;
	cur->next = NULL;

	for ( int i = 0; i < length - 1; ++i ) {
		new = ( ListNode * ) malloc( sizeof( ListNode ) );
		new->data = i+2;
		new->next = NULL;
		cur->next = new;
		cur = new;
	}

	return head;
}

void printList( ListNode *head )
{
	ListNode *cur = head;

	printf( "List:" );
	while( cur != NULL ) {
		printf( " %d", cur->data );
		cur = cur->next;
	}
	printf( "\n" );
}

void freeList( ListNode *head )
{
	ListNode *cur = head, *next = head->next;

	while( next != NULL ) {
		free( cur );
		cur = next;
		next = cur->next;
	}
	free( cur );

	head = NULL;
}
