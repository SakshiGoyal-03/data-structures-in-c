#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node* insert(struct node *root, int value)
{
    struct node *newnode,*prev,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->lchild = NULL;
    newnode->rchild = NULL;

    if(root == NULL)
    {
        root = newnode;
        return root;
    }
    else
    {
        temp = root;
        prev = NULL;

        while(temp!=NULL)
        {
            prev = temp;
            if(temp->data > value)
                temp = temp->lchild;
            else
                temp = temp->rchild;
        }
        if(prev->data > value)
            prev->lchild = newnode;
        else
            prev->rchild = newnode;

    }
    return root;

}
void preorder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}
main()
{
    struct node *root;
    int value;
    int choice;
    root = (struct node*)malloc(sizeof(struct node));
    root = NULL;
    printf("\nEnter 1 for creating a BST: ");
    printf("\nEnter 2 for inserting a node : ");
    printf("Enter # for exit: ");
    do
    {

      printf("\nEnter your choice : ");
      scanf("%d",&choice);

      switch(choice)
      {
      case 1:
        printf("Creating a tree \n");
        do
       {
          printf("Enter an element : ");
          scanf("%d",&value);
          if(value == -1)
            break;
           root = insert(root,value);
       }while(value!=-1);
       printf("Pre-order traversal of BST :" );
       preorder(root);
       break;

      case 2:
        printf("Enter an element for insertion : ");
        scanf("%d",&value);
        root = insert(root,value);
        printf("traversal of BST after insert : ");
        preorder(root);
        break;

      case 3:
        exit;
      }
      }while(choice!=3);



}
