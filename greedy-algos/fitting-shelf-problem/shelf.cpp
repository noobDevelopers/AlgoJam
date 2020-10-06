#include <bits/stdc++.h> 
using namespace std; 
  
void minSpace(int wall, int m, int n)
{
  /* algo for solving the issue*/
	int num_m = 0, num_n = 0, min_empty = wall; 
  	int p = 0, q = 0, rem; 
  
    while (wall >= n) 
    { 
        p = wall / m; 
        rem = wall % m; 
  
        if (rem <= min_empty) 
        { 
            num_m = p; 
            num_n = q; 
            min_empty = rem; 
        } 
        q += 1; 
        wall = wall - n; 
    } 
  
    cout << num_m << " " << num_n << " "
         << min_empty << endl;
  
}

  
// Driver code 
int main() 
{ 
    int wall = 24, m = 3, n = 5; 
    minSpace(wall, m, n);
  
    return 0; 
} 
