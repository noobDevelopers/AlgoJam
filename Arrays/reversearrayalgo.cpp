void rvereseArray(arr[], start, end) 
{ 
    if (start >= end) 
        return; 
    
    // Swap elements at start and end  
    temp = arr[start];  
    arr[start] = arr[end];
    arr[end] = temp; 
      
    // Recursive Function calling 
    rvereseArray(arr, start + 1, end - 1);  
}   
