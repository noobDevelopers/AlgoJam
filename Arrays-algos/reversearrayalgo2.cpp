void reversearray2(int arr[],int size)
{

	int rev[size];
	int j=0;
	for(int i=size-1;i>=0;i++)
	{
		rev[j]=arr[i];
		j++;
	}
	
	return rev;
	
}