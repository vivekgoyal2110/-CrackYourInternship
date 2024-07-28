//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void helper(vector<int>& arr, vector<vector<int>>& result, vector<int>& temp, vector<bool>& used) {
        if (temp.size() == arr.size()) {
            result.push_back(temp);
            return;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (used[i] || (i > 0 && arr[i] == arr[i - 1] && !used[i - 1])) continue;
            used[i] = true;
            temp.push_back(arr[i]);
            helper(arr, result, temp, used);
            temp.pop_back();
            used[i] = false;
        }
    }
  
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(arr.size(), false);
        helper(arr, result, temp, used);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends