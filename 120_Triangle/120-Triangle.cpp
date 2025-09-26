class Solution {
    int findMin(int i, int j,vector<vector<int>>&triangle, vector<vector<int>>&dp)
    {
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(i == 0)return dp[0][0] = triangle[0][0];
        if(j == 0)return dp[i][j] = triangle[i][j] + findMin(i-1, j, triangle, dp);
        if(i == j)return dp[i][j] = triangle[i][j] + findMin(i-1, j-1, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(findMin(i-1, j, triangle, dp),findMin(i-1, j-1, triangle, dp));
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));

        int ans = INT_MAX;

        for(int j = 0; j<n; ++j)
        {
            ans = min(ans, findMin(n-1, j, triangle, dp));
        }
        return ans;
    }
};