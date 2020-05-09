#include<stdio.h>
#include<stdlib.h>

void swaping(int *q ,int *w,int swap)
{
    int temp=*q;
    *q=*w;
    *w=temp;
    swap=1;
}

int main()
{
    int n;
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
    for(int x=n-2;x>=0;x--)
    {
        int swap=0;
        for(int y=0;y<=x;y++)
        {
            if(a[y]>a[y+1])
            {
                swaping(&a[y+1],&a[y],swap);
            }
        }
        if(swap==1)
        {
            break;
        }
    }
    printf("\nsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
