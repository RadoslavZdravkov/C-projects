#include <stdio.h>
#include <stdlib.h>

#define NL printf("\n")

int main()
{
    int numsCount=7;
    int sum1=0,sum2=0,sum3=0;
    int* arr=(int*)malloc(numsCount*sizeof(int));//malloc не нулира това, което се намира в запазената памет
    printf("Enter 7 numbers: ");
    for(int i=0;i<numsCount;i++)
    {
        scanf("%d",&arr[i]);
        sum1+=arr[i];
    }
    printf("sum1 = %d\n",sum1);
    printf("How many numbers to add: ");
    int n=0;
    scanf("%d",&n);
    int* ptrToArr=arr;
    arr=(int*)calloc((numsCount+n),sizeof(int));//calloc нулира елементите след запазване на памет
    for(int i=0;i<numsCount;i++)
    {
        arr[i]=ptrToArr[i];
    }
    printf("Enter the new %d nums:\n ",n);
    for(int i=numsCount;i<numsCount+n;i++)
    {
        scanf("%d",&arr[i]);
        sum2+=arr[i];
    }
    printf("sum2 = %d\n",sum2+sum1);
    printf("How many numbers to add: ");
    int m=0;
    scanf("%d",&m);
    arr=(int*)realloc(arr,sizeof(int)*(numsCount+n+m));
    printf("Enter the new %d nums:\n ",m);
    for(int i=numsCount+n;i<numsCount+n+m;i++)
    {
        scanf("%d",&arr[i]);
        sum3+=arr[i];
    }
    printf("sum3 = %d\n",sum3+sum2+sum1);
    for(int i=0;i<n+m+numsCount;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    free(ptrToArr);
    return 0;
}
