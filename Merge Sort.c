#include<stdio.h>
void mergesort(int a[],int l,int h)
{
    int m,j,k,i;
    if(l<h)
    {
        int b[h+1];
        m=(l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        i=l;
        j=m+1;
        k=l;
        while(i<=m && j<=h)
        {
            if(a[i]<a[j])
            {
                b[k]=a[i];
                k=k+1;
                i=i+1;
            }
            else
            {
                b[k]=a[j];
                k=k+1;
                j=j+1;
            }
        }
        while(i<=m)
        {
            b[k]=a[i];
            k=k+1;
            i=i+1;
        }
        while (j<=h)
        {
            b[k]=a[j];
            k=k+1;
            j=j+1;

        }
        for(k=l;k<=h;k++)
        a[k]=b[k];
     }

}
    int main()
{
    int j,i,n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Before sorting:");
    for(i=0;i<n;i++)
    printf("%d|",a[i]);
    printf("\nAfter sorting:");
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
    printf("%d|",a[i]);
    return 0;
}
