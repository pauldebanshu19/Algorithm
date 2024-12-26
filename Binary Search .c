#include <stdio.h>
int binarysearch(int a[],int n,int data)
{
    int l=0,u=n-1;
    while (l<=u)
    {
        int mid=(l+u)/2;
        if (a[mid]==data)
        {
            return mid;
        }
        else if(a[mid]<data)
        {
            l=mid+1;
        }
        else
        {
            u=mid-1;
        }
    }
    return -1;
}
int main()
{
    int n;
    printf("Enter the no. of elements to store in the array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements:\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int d;
    printf("Enter the data to be searched:");
    scanf("%d",&d);
    int r=binarysearch(a,n,d);
    if (r==-1)
    {
        printf("%d is not found in the array\n",d);
    }
    else
    {
        printf("%d is found at %d index of the array\n",d,r);
    }
}
