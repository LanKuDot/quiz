#ifndef __FLATTEN
#define __FLATTEN

typedef struct Node {
	struct Node *parent;
	struct Node *left;
	struct Node *right;
	int value;
} TreeNode;

void flatten( TreeNode *root );

#endif
