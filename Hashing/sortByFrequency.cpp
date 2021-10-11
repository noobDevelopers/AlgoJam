//https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1/
// Sorting Elements of an Array by Frequency 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    static bool cmp( pair<int, int> &a, pair<int, int> &b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        return a.second>b.second;
    }
   
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        vector<int>ans;
        map<int,int> m;
        vector<pair<int, int> > A;
        
        for(int i=0; i<n; i++)
        {
            int x= arr[i];
            m[x]++;
        }
        // Copy key-value pair from Map
        // to vector of pairs
        for (auto &it : m) {
            A.push_back(it);
        }
        sort(A.begin(), A.end(), cmp) ;
        
        for(auto x: A)
        {
           while(x.second)
           {
               ans.push_back(x.first);
               x.second--;
           }
            
        }   
        
        return ans;
    }
};

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}
