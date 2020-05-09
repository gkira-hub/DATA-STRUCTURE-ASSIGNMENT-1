//--------------------SELECTION SORT----------------------
#include<stdio.h>
#include<stdlib.h>

//SWAPPING
void swaping(int *q ,int *w)
{
    int temp=*q;
    *q=*w;
    *w=temp;
}

int main()
{
    int n,lowest;
    printf("enter size of array:");
    scanf("%d",&n);
    int a[n];
    printf("enter elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("unsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    //SELECTION SORT
    for(int x=0;x<n-1;x++)
    {
        lowest=x; //ASSIGNING VALUE TO  LOWEST INDEX VALUE FOR MAKING VALUE AT THIS INDEX LOWEST BY SWAPPING AND COMPERISONS
        for(int y=x+1;y<n;y++)
        {
            if(a[y]<a[lowest])
            {
                lowest=y;
            }
        }
        if(x!=lowest)
        {
            swaping(&a[x],&a[lowest]);
        }
    }
    printf("\nsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
