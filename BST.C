#include <stdio.h>
#include <stdlib.h>
struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
};
typedef struct BST NODE;
NODE *root,*temp;
NODE* createtree(NODE *root, int data)
{
	if (root == NULL)
	{
//NODE *temp;
		temp= (NODE*)malloc(sizeof(NODE));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}
	if (data < (root->data))
	{
		root->left = createtree(root->left, data);
	}
	else if (data > root->data)
	{
		root -> right = createtree(root->right, data);
	}
	return root;
}
NODE* search(NODE *root, int data)
{
	if(root == NULL)
	printf("\nElement not found");
	else if(data < root->data)
	{
		root->left=search(root->left, data);
	}
	else if(data > root->data)
	{
		root->right=search(root->right, data);
	}
	else printf("\nElement found is: %d", root->data);
	return root;
}
void inorder(NODE *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}
void preorder(NODE *root)
{
	if(root != NULL)
	{
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(NODE *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}
NODE* findMin(NODE *root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->left)
	return findMin(root->left);
	else
	return root;
}
NODE* del(NODE *root, int data)
{
//NODE *temp;
	if(root == NULL)
	{
		printf("\nElement not found");
	}
	else if(data < root->data)
	{
		root->left = del(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = del(root->right, data);
	}
	else
	{
		if(root->right && root->left)
		{
			temp = findMin(root->right);
			root-> data = temp->data;
			root-> right = del(root->right,temp->data);

		}
		else
		{
			temp = root;
			if(root->left == NULL)
			root = root->right;
			else if(root->right == NULL)
			root = root->left;
			free(temp);
/* temp is longer required */
		}
	}
	return root;
}
void main()
{
	int data, ch, i, n;
	NODE *root=NULL;
	clrscr();
	while (1)
	{
		printf("\n1.Insertion in Binary Search Tree");
		printf("\n2.Search Element in Binary Search Tree");
		 printf("\n3.Delete Element in Binary Search Tree");
		printf("\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
			case 1: printf("\nEnter Number of values: " );
			scanf("%d", &n);
			printf("\nEnter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)\n");
			for(i=0; i<n; i++)
			{
				scanf("%d", &data);
				root=createtree(root, data);
			} break;
			case 2: printf("\nEnter the element to search: "); scanf("%d", &data); root=search(root, data); break;
			case 3: printf("\nEnter the element to delete: "); scanf("%d", &data); root=del(root, data); break;

			case 4: printf("\nInorder Traversal: \n");
				inorder(root); break;
			case 5: printf("\nPreorder Traversal: \n");
				preorder(root); break;
			case 6: printf("\nPostorder Traversal: \n");
				postorder(root); break;
			case 7: exit(0);
			default:printf("\nWrong option");
			break;
		}
	}
 getch();
}

