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

int sort(int arr[],int search)
{


    // You have to sort the array and call the binary function and return the result you get from that function to the main.

    int result = binary_search(sorted_array_name, search_element, initial_lower_value, initial_upper value );
    return result;
}


int main() 
{
  int array[] = {6, 4, 8, 1, 2, 5, 3};
  int search;
  cout<<"Enter search element"<<endl;
  cin>>search;
  int size = sizeof(array) / sizeof(array[0]);
  int result = sort(array, search);
  if (result == -1)
    cout<<"Element not found"<<endl;
  else
    cout<<"Element is found at index "<<result<<endl;
}