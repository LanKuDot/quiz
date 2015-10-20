#include <stdlib.h>

#include "flatten.h"

void flatten( TreeNode *root )
{
	TreeNode *pop = root, *stack[8];
	int stack_top = -1;

	while( pop != NULL || stack_top != -1 ) {
		if ( pop->right != NULL )
			stack[++stack_top] = pop->right;

		if ( pop->left != NULL ) {
			pop->right = pop->left;
			pop->left = NULL;
		} else if ( stack_top != -1 ) {
			pop->right = stack[stack_top--];
		}

		pop = pop->right;
	}
}
