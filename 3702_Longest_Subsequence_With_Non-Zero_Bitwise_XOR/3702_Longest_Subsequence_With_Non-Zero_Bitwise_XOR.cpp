class Solution {
public:
    int longestSubsequence(vector<int>& nums) { 
        int Xor  = 0;
        int n = nums.size();
        bool hasNonZero = false;
        for(int i = 0; i<n; ++i)
        {
            Xor^= nums[i];
            if(nums[i] != 0)
                hasNonZero = true;
        }
        if(Xor!=0)
            return n;
        if(hasNonZero)
            return n-1;
        return 0;
    }
};