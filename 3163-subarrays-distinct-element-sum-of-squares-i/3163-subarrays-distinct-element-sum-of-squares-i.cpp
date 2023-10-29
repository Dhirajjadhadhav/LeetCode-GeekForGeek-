class Solution {
 
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i<nums.size(); ++i)
        {
            unordered_map<int, int>mp;
            int count = 0;
            for(int j = i; j<nums.size(); ++j)
            {
                mp[nums[j]]++;
                if(mp[nums[j]] == 1)count++;
                ans+= count*count;
            }
        }
        return ans;
    }
};