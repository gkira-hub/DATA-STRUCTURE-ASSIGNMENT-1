#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,temp,x,y;
    printf("enter size of array:");
    scanf("%d",&n);
    int a[2*n];
    printf("enter elements of array:");
   for(int i=0;i<2*n;i++)
        a[i]=77777777;
    printf("enter elements of array:");
    for(int i=n-1;i<2*n-1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("unsorted array:");
    for(int i=n-1;i<2*n-1;i++)
    {
        printf("%d\t",a[i]);
    }
    for( x=n-1;x<2*n-1;x++)
    {
        temp=a[x];
        for(y=x-1;y>=0 && a[y]>temp;y--)
        {
            a[y+1]=a[y];
        }
        a[y+1]=temp;
    }
    printf("\nsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
