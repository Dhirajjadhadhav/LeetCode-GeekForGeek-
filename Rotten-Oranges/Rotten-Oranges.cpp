//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        int minTime = 0;
        vector<vector<bool>>vis(n, vector<bool>(m, false));
        //i  j, time;
        queue<pair<pair<int, int>, int>>q;
        
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<m; ++j)
            {
                if(mat[i][j] == 2)
               {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
               }
            }
        }
        
        vector<int>delRow = {1 ,-1, 0, 0};
        vector<int>delCol = {0, 0, -1, 1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            minTime = max(minTime, t);
            
            for(int i = 0; i<4; ++i){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && 
                        mat[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = true;
                }
            }  
        }
        
        for(int i = 0; i<n; ++i)
        {
            for(int j = 0; j<m; ++j)
            {
                if(!vis[i][j] && mat[i][j] == 1)return -1;
            }
        }
        return minTime;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends