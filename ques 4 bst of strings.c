//-------------------------INSERTION IN BST OF STRINGS---------------------
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define COUNT 10
#define MAX 15

struct node{
    char *name;
    struct node* left;
    struct node* right;
}*Node;

//FUNCATION FOR CREATING A NODE IN BST
struct node *createNode(char *x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    if(strcmp(x,"empty")==0)
        return NULL;
    temp->name=x;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

//FUNCATION FOR INSERTING A NEW NODE IN BST AFTER FINDING A SUITABLE POSITION FOR IT USING STRCMP 
struct node* insert(char* x,struct node* p)
{
struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=p;
    while(1)
        {
        if(temp)
        {
            if(strcmp(temp->name,x)>0)
            {
                if(temp->left)
                    temp=temp->left;
                else
                {
                    temp->left=createNode(x);
                    return;
                }
            }
            else
                {
                if(temp->right)
                    temp=temp->right;
                else{
                    temp->right=createNode(x);
                    return;
                    }
                }
        }
        }
}

//INORDER TRANSVERSAL OF BST
int inorder(struct node *p)
{
    if(p==NULL)
    {
        return;
    }
    inorder(p->left);
    puts(p->name);
    inorder(p->right);

}
int main()
{
        char a[COUNT][MAX]={"Arthi","Christy","Dorothy","Fraser","Eliza"};//NAMES TO STORE IN BST
        struct node* root=createNode(a[0]);
        for(int i=1;i<5;i++)
        insert(a[i],root);
        printf("INORDER TRANSVERSAL OF BST BEFORE INSERTING DAVID:-\n");
        inorder(root);
        insert("David",root);
        printf("\n\nINORDER TRANSVERSAL OF BST AFTER INSERTING DAVID:-\n");
        inorder(root);
}
