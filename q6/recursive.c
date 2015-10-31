#include <stdlib.h>
#include "reverseBetween.h"

ListNode *doReverse( ListNode *head );

ListNode *reverseBetween( ListNode *head, int m, int n )
{
	if ( m == n ) return head;

	// Extract the sub linked list which would be reversed.
	ListNode *connect, *subHead, *tail, *tmp;
	int i;

	connect = head;

	// Find the first element in the reverse interval and
	// the last element before the reverse interval
	for ( i = 1; i < m-1; ++i, connect = connect->next )
		;

	// Find the last element in the reverse interval
	tmp = connect;
	for ( ; i < n; ++i, tmp = tmp->next )
		;
	// Store the next element behind the reverse interval
	tail = tmp->next;
	// Cut!
	tmp->next = NULL;

	if ( m != 1 ) {
		subHead = connect->next;
		connect->next = doReverse( subHead );
	} else {
		subHead = head;
		head = doReverse( subHead );
	}

	subHead->next = tail;

	return head;
}

ListNode *doReverse( ListNode *head )
{
	// No element there.
	if ( head == NULL ) return NULL;
	// Only one element.
	if ( head->next == NULL ) return head;

	ListNode *right = head->next, *newHead;

	head->next = NULL;

	newHead = doReverse( right );

	right->next = head;

	return newHead;
}
