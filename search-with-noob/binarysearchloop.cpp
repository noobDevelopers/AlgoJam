#include<bits/stdc++.h>
using namespace std;
int bs(int arr[], int l, int r, int x)
{
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]==x)
			return mid;
		if(arr[mid]>x)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return -1;
}
int main(int argc, char const *argv[])
{
	int n,x,ans;
	cout<<"Enter the array size"<<"\n";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter the element to be searched"<<"\n";
	cin>>x;
	ans=bs(arr, 0, n-1, x);
	(ans==-1)?cout<<"Not Found!!":cout<<ans;
	return 0;
}
