class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>res;

        res.push_back({1});
        res.push_back({1,1});
        for(int i = 2; i<=rowIndex; ++i)
        {
            res.push_back(vector<int>(i+1));
            res[i][0] = 1;
            res[i][i] = 1;
            for(int j = 1; j<i; ++j)
                res[i][j] = res[i-1][j] + res[i-1][j-1];
        }
        return res[rowIndex];
    }
};