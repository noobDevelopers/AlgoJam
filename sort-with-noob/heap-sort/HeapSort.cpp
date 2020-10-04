/*
 * C++ Program to Implement Min Heap
 * Modify this code to Max Heap and also make this code work for char inputs
 */

#include <iostream>
using namespace std;

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void minHeapify(int *a,int i,int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j+1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        else if (temp >= a[j])
        {
            a[j/2] = a[j];
            j = 2 * j;
        }
    }
    a[j/2] = temp;
    return;
}
//build heap
void buildMinHeap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        minHeapify(a,i,n);
    }
}

// Driver program 
int main()
{
    int array[20],n,i;
    cout<<"Enter the number of elements\n";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter the element\n";
        cin>>array[i];
    }
    buildMinHeap(array,n);
    cout<<"Min heap--->>\n";
     for (i = 1; i <= n; i++)
    {
        cout<<array[i]<<endl;
    }

}