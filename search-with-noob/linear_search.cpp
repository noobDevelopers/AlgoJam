#include<iostream>
using namespace std;

int linear_search(int arr[],int size,int search_element)
{   
    for(int i=0;i<size;i++)
    {
        if (arr[i]==search_element)
            return i;
    }
    return -1;
}

int main()
{
    int arr[]={2,9,5,7,1,57,2,84};
    int size=sizeof(arr)/sizeof(arr[0]);

    int search_element;
    //Take the input of the element to be searched by the user.
	cout<<"Enter the search element"<<endl;
	cin>>search_element;


    int result = linear_search(arr,size,search_element);

    //If the result is -1 then print that the element is not present in the array.
    //If the result is any value but -1 then print the element is found on that index.
	if(result==-1)
		cout<<"Element not found"<<endl;
	else
		cout<<"Element found at index "<<i<<endl;

    return 0;

}