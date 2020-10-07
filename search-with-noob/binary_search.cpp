#include <iostream>
using namespace std;

int binary_search(int array[], int search, int lower, int upper) 
{

  if (upper >= lower) 
  {
    int middle = lower + (upper-lower) / 2;

    if (array[middle] == search)
      return middle;

    if (array[middle] > search)
      return binary_search(array, search, lower, middle - 1);

    return binary_search(array, search, middle + 1, upper);
  }

  return -1;
}

//Since the Binary Search needs a sorted array but we have an unsorted array so it needs to be sorted first.
//You can use any sorting method as per your convenience.

int sort(int arr[],int search, int size)
{

  for (int step = 0; step < size - 1; ++step) 
  {
    for (int i = 0; i < size - step - 1; ++i) 
	{
      if (arr[i] > arr[i + 1]) 
	  {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }  
}

    // You have to sort the array and call the binary function and return the result you get from that function to the main.

    int result = binary_search(arr, search, 0, size-1 );
    return result;
}


int main() 
{
  int array[] = {6, 4, 8, 1, 2, 5, 3};
  int search;
  cout<<"Enter search element"<<endl;
  cin>>search;
  int size = sizeof(array) / sizeof(array[0]);
  int result = sort(array, search,size);
  if (result == -1)
    cout<<"Element not found"<<endl;
  else
    cout<<"Element is found at index "<<result<<endl;
}