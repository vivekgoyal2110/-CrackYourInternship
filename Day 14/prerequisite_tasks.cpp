//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
        vector<int> indegree(N, 0);
        for(auto it : prerequisites){
            adj[it.second].push_back(it.first);
            indegree[it.first]++;
        }

        queue<int> q;
        int count = 0;
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        // vector<int> ans;
        while(q.size()){
            int node = q.front();
            q.pop();
            // ans.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    count++;
                } 
            }
        }
        return count == N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends