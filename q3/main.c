#include <stdio.h>
#include <stdlib.h>

#include "flatten.h"

#define BUF_LEN 32

void build_binaryTree( TreeNode *root, FILE *fp );
void free_binaryTree( TreeNode *node );
void DFS( TreeNode *root );

int main()
{
	/* Read the preorder from the file. */
	FILE *fp = fopen( "build_tree.txt", "r" );

	TreeNode *root = (TreeNode *) malloc( sizeof( TreeNode ) );
	root->parent = NULL;
	root->left = NULL;
	root->right = NULL;
	root->value = 0;

	build_binaryTree( root, fp );
	fclose( fp );

	DFS( root );

	free_binaryTree( root );
}

void build_binaryTree( TreeNode *root, FILE *fp )
{
	int bytes_read = 0, node_count = 0;
	char buffer[ BUF_LEN + 1 ], *ch_ptr;
	TreeNode *parent_cur = root, *new = NULL;

	while( ( bytes_read = fread( buffer, sizeof( char ), BUF_LEN, fp ) ) != 0 ) {
		buffer[ bytes_read ] = '\0';
		ch_ptr = buffer;

		/* format: L(L(LR)R)R(L(L)R) */
		while( *ch_ptr != '\0' ) {
			switch( *ch_ptr++ ) {
			case '(':
				parent_cur = new;
				break;
			case ')':
				parent_cur = parent_cur->parent;
				break;
			case 'L':
				new = (TreeNode *) malloc( sizeof(TreeNode) );
				new->parent = parent_cur;
				new->left = NULL;
				new->right = NULL;
				parent_cur->left = new;
				new->value = ++node_count;
				break;
			case 'R':
				new = (TreeNode *) malloc( sizeof(TreeNode) );
				new->parent = parent_cur;
				new->left = NULL;
				new->right = NULL;
				parent_cur->right = new;
				new->value = ++node_count;
				break;
			}
		}
	}
}

/* TODO: Iterative version.
 */
void free_binaryTree( TreeNode *node )
{
	if( node->left != NULL )
		free_binaryTree( node->left );
	if( node->right != NULL )
		free_binaryTree( node->right );
	free( node );
}

void DFS( TreeNode *root )
{
	TreeNode *stack[16], *pop;
	int stack_top = -1;

	printf( "DFS:" );

	stack[++stack_top] = root;
	while( stack_top != -1 ) {
		pop = stack[stack_top--];
		printf( " %d", pop->value );

		if ( pop->right != NULL )
			stack[++stack_top] = pop->right;
		if ( pop->left != NULL )
			stack[++stack_top] = pop->left;
	}

	printf( "\n" );
}
