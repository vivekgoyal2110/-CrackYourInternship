//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> in_degree(V, 0);
        
        // Calculate in-degrees of all vertices
        for (int i = 0; i < V; i++) {
            for (int node : adj[i]) {
                in_degree[node]++;
            }
        }

        queue<int> q;
        
        // Enqueue vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo_order;
        
        // Process the queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo_order.push_back(node);
            
            // Decrease the in-degree of adjacent vertices
            for (int neighbor : adj[node]) {
                in_degree[neighbor]--;
                // If in-degree becomes 0, enqueue the vertex
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check if there was a cycle
        if (topo_order.size() != V) {
            // This indicates there is a cycle in the graph.
            // As per problem statement, we are given a DAG, so we should not
            // reach here. Hence, this part is more for completeness.
            return {};
        }

        return topo_order;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends