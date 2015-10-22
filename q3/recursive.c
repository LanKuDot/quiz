#include <stdlib.h>

#include "flatten.h"

TreeNode *doFlat( TreeNode *node );

void flatten( TreeNode *root )
{
	if ( root == NULL )
		return;

	doFlat( root );
}

TreeNode *doFlat( TreeNode *node )
{
	TreeNode *carry = NULL;

	if ( node->right != NULL )
		carry = node->right;

	if ( node->left != NULL ) {
		node->right = node->left;
		node->right->parent = node;
		node->left = NULL;
		node = doFlat( node->right );
	}

	if ( carry != NULL ) {
		node->right = carry;
		node->right->parent = node;
		node = doFlat( node->right );
	}

	return node;
}
