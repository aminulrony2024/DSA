#include<stdio.h>
#include<stdlib.h>
typedef struct treeNode Tnode;
struct treeNode
{
    int data;
    struct treeNode *left, *right;
};
Tnode *create()
{
    int x;
    Tnode *new_node = NULL;
    new_node = (Tnode *) malloc(sizeof(Tnode));
    printf("\nEnter data (-1 for no Node.) : ");
    scanf("%d",&x);
    if(x == -1)
    return 0;
    else
    new_node -> data = x;
    printf("\nEnter left child of %d",x);
    new_node -> left = create();
    printf("\nEnter Right child : ");
    new_node -> right = create();
    return new_node;
}
void preOrder(Tnode *root)
{
    if(root == NULL)
    return;
    printf("%d ",root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}
void inOrder(Tnode *root)
{
    if(root == NULL)
    return;
    inOrder(root -> left);
    printf("%d ",root -> data);
    inOrder(root -> right);
}
void postOrder(Tnode *root)
{
    if(root == NULL)
    return;
    postOrder(root -> left);
    postOrder(root -> right);
    printf("%d ",root -> data);
}
int main()
{
    Tnode *root = NULL;
    int n;
    do
    {
        printf("\n1.Create  Binary Tree\n");
        printf("2.Pre Order Traversal\n");
        printf("3.In Order Traversal\n");
        printf("4.Post Order Traversal\n");
        printf("Enter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 :
            {
                root = create();
                break;
            }
            case 2 :
            {
                preOrder(root);
                break;
            }
            case 3 :
            {
                inOrder(root);
                break;
            }
            case 4 :
            {
                postOrder(root);
                break;
            }
            case 5 :
            exit(1);
        };
    } while ( n != 5);
    return 0;
}