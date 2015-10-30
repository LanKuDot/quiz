#ifndef REV_BETWEEN
#define REV_BETWEEN

typedef struct NODE {
	int data;
	struct NODE* next;
} ListNode;

ListNode *reverseBetween( ListNode *head, int m, int n );

#endif
