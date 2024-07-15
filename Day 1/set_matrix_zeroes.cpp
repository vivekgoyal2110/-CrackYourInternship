class Solution {
public:

    void helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& vis, int n, int m){
        vis[i][j] = 1;
        for(int ind = 0; ind < m; ind++){
            if(!vis[i][ind]){
                if(matrix[i][ind] == 0) continue;
                matrix[i][ind] = 0;
                vis[i][ind] = 1;
            }
        }
        for(int ind = 0; ind < n; ind++){
            if(!vis[ind][j]){
                if(matrix[ind][j] == 0) continue;
                matrix[ind][j] = 0;
                // vis[matrix[i][ind]] = 1;
                vis[ind][j] = 1;
            }
        }
        return;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                    if(matrix[i][j] == 0 && !vis[i][j]){
                        helper(i, j, matrix, vis, n, m);
                        // break;
                    }
                }
            }
        }
    }
;