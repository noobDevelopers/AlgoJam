#include<stdio.h>
#include<stdlib.h>
//****************************************************************************************
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

//*****************************************************************************************
void  merge(int ar[],int p,int q,int r)                                                             //MERGESORT ALGORITHM STARTS.......
{
    int n1=(q-p)+1;
    int n2=r-q;
    int a[n1],b[n2];
    for(int count=0;count<n1;count++)
        a[count]=ar[p+count];
    for(int count=0;count<n2;count++)
        b[count]=ar[q+1+count];
    int i=0;
    int j=0,k=p;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            ar[k]=a[i];
            i++;
        }
        else
        {
            ar[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        ar[k]=a[i];
        i++;k++;
    }
    while(j<n2)
    {
        ar[k]=b[j];
        j++;k++;
    }
}

void msort(int arr[],int f,int l)
{
    if(f<l)
    {
        int m=(f+l-1)/2;
        msort(arr,f,m);
        msort(arr,m+1,l);
        merge(arr,f,m,l);
    }
}
//*************************************************************************************************************
void display(int ar[],int size)
{
    printf("The Sorted array is:\n");
    for(int count=0;count<size;count++)
        printf("%d\t",ar[count]);
    printf("\n");
}
//*************************************************************************************************************
int main()
{
    int n;
    
    printf("Enter number of elements to be sorted:\t");
    scanf("%d",&n);
    
    int arr[n];

    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    msort(arr,0,n-1);
    
    display(arr,n);
    
    return 0;
}
