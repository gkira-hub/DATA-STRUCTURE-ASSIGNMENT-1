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


int inorder(struct node *p)
{
    if(p==NULL)
    {
        return;
    }
    puts(p->name);
    inorder(p->left);
    inorder(p->right);

}
int main()
{
        char a[COUNT][MAX]={"Arthi","Christy","Dorothy","Fraser","Eliza"};
        struct node* root=createNode(a[0]);
        for(int i=1;i<5;i++)
        insert(a[i],root);
        printf("INORDER TRANSVERSAL OF BST BEFORE INSERTING DAVID:-\n");
        inorder(root);
        insert("David",root);
        printf("\n\nINORDER TRANSVERSAL OF BST AFTER INSERTING DAVID:-\n");
        inorder(root);
}
