//------------------SORTING OF STRING USING MERGE SORT ----------------------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

//FOR CASE INSENSTIVE CASE(CONVERTING ALL STRING ELEMENTS INTO LOWERCASE USING ACSII CODES
int case_conversion(char str[])
{
   for(int i=0;i<=strlen(str);i++)
   {
      if(str[i]>=65&&str[i]<=90)
         str[i]=str[i]+32;
   }
    return 0;
}

//MERGING
void merging(char a[],int temp[],int start1,int end1,int start2,int end2)
{
    int p=start1;
    int q=start2;
    int r=start1;

    while((p<=end1) && (q<=end2))
    {
        if(a[p]>a[q])
        {
            temp[r++]=a[q++];
        }
        else
        {
            temp[r++]=a[p++];
        }
    }
    while(p<=end1)
    {
        temp[r++]=a[p++];
    }
    while(q<=end2)
    {
        temp[r++]=a[q++];
    }
}
void merge_sort(char a[],int start,int end)
{
    int temp[MAX];
    int middle;
    middle=(start+end)/2;

    if(start==end)
    {
        return;
    }
    merge_sort(a,start,middle);
    merge_sort(a,middle+1,end);

    merging(a,temp,start,middle,middle+1,end);
    for(int i=start;i<=end;i++)
    {
        a[i]=temp[i];
    }
}

int main()
{
    char a[MAX] = "Polynomial";//GIVEN STRINGS FOR SORTING
    char b[MAX] = "Test Case";


    printf("1:-unsorted array:");
    for(int i=0;i<strlen(a);i++)
    {
        printf("%c",a[i]);//PRINTING UNSORTED STRING
    }

    merge_sort(a,0,strlen(a)-1);//MEGE SORT FUNCATION CALL

    printf("\tsorted array(case senstive):");
    for(int i=0;i<strlen(a);i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");

    case_conversion(a);//CHANGING STRING INTO LOWER CASE FOR NOT CASE SENSTIVE SORTING
    merge_sort(a,0,strlen(a)-1);

    printf("\t\t\t\tsorted array(not case senstive):");
    for(int i=0;i<strlen(a);i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");

//-------------------------------------------------------------------------------------------------------------------------------------------------

//SORTING OF SECOND STRING

    printf("2:-unsorted array:");
    for(int i=0;i<strlen(b);i++)
    {
        printf("%c",b[i]);
    }

    merge_sort(b,0,strlen(b)-1);

    printf("\tsorted array(case senstive):");
    for(int i=0;i<strlen(b);i++)
    {
        printf("%c",b[i]);
    }
    printf("\n");

    case_conversion(b);
    merge_sort(b,0,strlen(b)-1);

    printf("\t\t\t\tsorted array(not case senstive):");
    for(int i=0;i<strlen(b);i++)
    {
        printf("%c",b[i]);
    }
}
