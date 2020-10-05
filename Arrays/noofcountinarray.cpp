int first_index(arr, low, high, x, n)
{

    if(high >= low) 
    {
        mid = (low + high)/2  /*low + (high - low)/2*/
        if( ( mid == 0 || x > arr[mid-1]) && arr[mid] == x) :
            return mid
        else if(x > arr[mid]) :
            return first_index(arr, (mid + 1), high, x, n)
        else :
            return first_index(arr, low, (mid -1), x, n)
    }
}

int last_index(arr, low, high, x, n):
{
    if (high >= low) 
    {
        int mid = (low + high)/2  /*low + (high - low)/2*/
        if( ( mid == n-1 || x < arr[mid+1]) && arr[mid] == x ) 
            return mid
        else if(x < arr[mid]) :
            return last_index(arr, low, (mid -1), x, n)
        else :
            return last_index(arr, (mid + 1), high, x, n)
    }
}

int count_occurences(arr, n, x) 
{
    i = first_index(arr, 0, n-1, x, n)
    j = last_index(arr, 0, n-1, x, n)
    count = j-i + 1
    return count
}