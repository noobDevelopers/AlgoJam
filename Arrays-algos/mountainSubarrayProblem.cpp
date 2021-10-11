// https://practice.geeksforgeeks.org/problems/mountain-subarray-problem/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,
                                int q) {
       
        vector<bool>ans;
        int left[n], right[n];
        left[0]=0;
        right[n-1]=n-1;
        int k=0;
        
        // left[i] stores the last index on left side which is increasing 
        // i.e. greater than its previous element
        for(int i=1; i<n; i++)
            {
                if(a[i-1]<a[i])
                    k=i;
                left[i]=k;
            }
        // right[i] will store the first index on the right side which is decreasing 
        // i.e. greater than its next element. 
        for(int i=n-2; i>=0; i--)  
        {
            if(a[i+1]<a[i])
                k=i;
            right[i]=k;
            
        }
        
        for(auto x: queries)
        {
            int l= x.first;
            int r= x.second;
            
            if(left[r]<=right[l])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
    return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
} 