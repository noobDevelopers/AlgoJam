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
	scanf("%d",&search_element);


    int result = linear_search(arr,size,search_element);

    //If the result is -1 then print that the element is not present in the array.
	if(result==-1)
		printf("element not found\n");
    //If the result is any value but -1 then print the element is found on that index.
	else
		printf("element found at index %d",result);
    return 0;

}