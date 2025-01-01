#include <stdio.h>
int partition(int a[],int lb,int ub)
{
    int t,temp;
    int pivot=a[lb];
    int start=lb;
    int end=ub;
    do
    {
        while (a[start]<=pivot)
        {
            start++;
        }
        while (a[end]>pivot)
        {
            end--;
        }
        if (start<end)
        {
            t=a[start];
            a[start]=a[end];
            a[end]=t;
        }
    }while(start<end);
    temp=a[lb];
    a[lb]=a[end];
    a[end]=temp;
    return end;
}
void quicksort(int a[],int lb,int ub)
{
    if (lb<ub)
    {
        int loc=partition(a,lb,ub);
        quicksort(a,lb,loc-1);
        quicksort(a,loc+1,ub);
    }
}
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting:\n");
    for (int i=0;i<n;i++)
    {
        printf("%d|",arr[i]);
    }
    printf("\n");
    quicksort(arr,0,n-1);
    printf("Array after implementing quicksort:\n");
    for (int i=0;i<n;i++)
    {
        printf("%d|",arr[i]);
    }
}
