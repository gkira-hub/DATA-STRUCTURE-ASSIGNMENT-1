//-----------------------MODIFIED INSERTION SORT----------------------------------

#include<stdio.h>
#include<stdlib.h>

//BINARY SEARCH TO FIND CORRECT INDEX FOR A ELEMENT
int binary_Search(int a[], int item, int low, int high)
{
    if (high <= low)
    {
        if(item > a[low])
            return low+1;
        else
            return low;
    }

    int mid = (low + high)/2;

    if(item == a[mid])
        return mid+1;

    if(item > a[mid])
        return binary_Search(a, item, mid+1, high);//SEARCH IN LEFT SUBARRAY
    return binary_Search(a, item, low, mid-1);//SEARCH IN RIGHT SUB ARRAY
}

int main()
{
    int n,temp,x,y,index;
    printf("enter size of array:");
    scanf("%d",&n);//SIZE OF ARRAY
    int a[2*n];
    for(int i=0;i<2*n;i++)
        a[i]=777777777;//STORING VARY LARGE NO IN ARRAY
    printf("enter elements of array:");
    for(int i=n-1;i<2*n-1;i++)
    {
        scanf("%d",&a[i]); //ELEENTS OF ARRAY
    }
    printf("unsorted array:");
    for(int i=n-1;i<2*n-1;i++)
    {
        printf("%d\t",a[i]);
    }
    for( x=n-1;x<2*n-1;x++)//INSERTION SORT
    {
        temp=a[x];
        y=x-1;
        index = binary_Search(a,temp,0,y);
        while(y>=index)
        {
            a[y+1]=a[y];
            y--;
        }
        a[y+1]=temp;
    }
    printf("\nsorted array:");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
