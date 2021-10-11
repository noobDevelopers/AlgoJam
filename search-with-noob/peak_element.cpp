// https://practice.geeksforgeeks.org/problems/peak-element/1/
// An element is called a peak element if its value is not smaller than the value of its adjacent elements(if they exists).
// Given an array arr[] of size N, find the index of any one of its peak elements.

//Binary Search is used

#include<stdio.h>
#include<stdbool.h>

int peakElement(int a[], int n)
{
   int l=0, u=n-1, mid;
   while(l<=u)
   {
       mid= l+(u-l)/2;
       if(mid==n-1 && a[mid]>=a[mid-1])
        return mid;
       else if(mid==0 && a[mid]>=a[mid+1])
        return mid;
       else if(a[mid]>=a[mid-1] && a[mid]>=a[mid+1])
        return mid;
       else 
         l=mid+1;
   }
   l=0, u=n-1, mid;
   while(l<=u)
   {
       mid= l+(u-l)/2;
       if(mid==n-1 && a[mid]>=a[mid-1])
        return mid;
       else if(mid==0 && a[mid]>=a[mid+1])
        return mid;
       else if(a[mid]>=a[mid-1] && a[mid]>=a[mid+1])
        return mid;
       else 
        return u=mid-1;
   }
   return -1;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			tmp[i] = a[i];
		}
		bool f=0;
		
		int A = peakElement(tmp,n);
		
		if(A<0 && A>=n)
		    printf("0\n");
		else
		{
		if(n==1 && A==0)
		f=1;
		else
		if(A==0 && a[0]>=a[1])
		f=1;
		else if(A==n-1 && a[n-1]>=a[n-2])
		f=1;
		else if(a[A]>=a[A+1] && a[A]>= a[A-1])
		f=1;
		else
		f=0;
		printf("%d\n", f);
		}
		
	}

	return 0;
}  