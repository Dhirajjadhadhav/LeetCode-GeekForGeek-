class Solution {
    void backtrack(int index, vector<int>&nums, vector<int>path, vector<vector<int>>&res){
        res.push_back(path);

        for(int i = index; i<nums.size(); ++i){
            if(i>index && nums[i-1] ==nums[i])continue;
            path.push_back(nums[i]);
            backtrack(i+1, nums, path, res);
            path.pop_back();                
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>>res;
        sort(nums.begin(), nums.end());
        vector<int>path;
        backtrack(0, nums, path, res);
        return res;
    }
};