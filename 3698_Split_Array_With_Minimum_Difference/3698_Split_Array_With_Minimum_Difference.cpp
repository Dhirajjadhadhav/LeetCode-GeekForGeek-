class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        long long lsum = 0;
        long long rsum = 0;
        int l = 0, r = n-1;

        // strictly increasing from left
        while(l < n-1 && nums[l] < nums[l+1])
            lsum += nums[l++];
        
        // strictly decrasing from right
        while( r > 0 && nums[r-1] > nums[r])
            rsum += nums[r--];
        
        // single peak
        if(l == r)
        {
            long long op1  = abs((lsum + nums[l]) - rsum);
            long long op2 = abs(lsum - (nums[l] + rsum));
            return min(op1, op2);
        }
        else if(r-l == 1 && nums[l] == nums[r])
            return abs(lsum - rsum);
        else
            return -1;
    }   

};