#include "reverseBetween.h"

// Note that m and n count from 1
ListNode *reverseBetween( ListNode *head, int m, int n )
{
	if ( m == n ) return head;

	ListNode *connect = head, *prev, *cur, *next;
	int i;

	// Find the one which is in front of the reverse interval.
	for ( i = 1; i < m - 1; ++i, connect = connect->next )
		;

	// Find the one which is behind of the reverse interval.
	prev = connect;
	for ( ; i < n + 1; ++i, prev = prev->next )
		;

	// Reverse interval
	if ( m == 1 )
		cur = head;
	else
		cur = connect->next;
	next = cur->next;
	for ( i = n - m + 1; i != 0; --i ) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	// Connect
	if ( m != 1 )
		connect->next = prev;
	else
		head = prev;

	return head;
}
