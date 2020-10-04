#include<bits/stdc++.h>
using namespace std;

/*
flip function reverses the array elements
from 0 to ith index.
*/
void flip(int arr[], int i)
{
  //complete the flip function.
  int start = 0;
  while(start<i)
  {
    //swapping start index and ith index element.
    int temp = arr[start];
    arr[start] = arr[i];
    arr[i] = temp;
    
    start++;
    i--;
  }
    
}

/* findMax finds the maximum element among the elements till nth index */
int findMax(int arr[], int n)
{
  int mi, i;  
  for (mi = 0, i = 0; i < n; ++i)
  {
    if (arr[i] > arr[mi]) 
    {
            mi = i;  
    }
  }
  return mi;  
}


int panSort(int *arr, int n)  
{   
    for (int curr_size = n; curr_size > 1; --curr_size)  
    {  
        // Find index of the the maximum element till curr size. 
        int mi = findMax(arr, curr_size);  
        //doing the two flips to bring max element at last if already not present.
        if (mi != curr_size-1)  
        {  
            flip(arr, mi);  
            flip(arr, curr_size-1);  
        }  
    }  
} 

void printArray(int arr[], int n)  
{  
    for (int i = 0; i < n; ++i)  
        cout<< arr[i]<<" ";  
} 

int main()  
{  
    int arr[] = {23, 10, 20, 11, 12, 6, 7};  
    int n = sizeof(arr)/sizeof(arr[0]);  
  
    panSort(arr, n);  
  
    cout<<"Sorted Array "<<endl;  
    printArray(arr, n);  
  
    return 0;  
}  
