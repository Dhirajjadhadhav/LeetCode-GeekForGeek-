class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();
        auto canMakeArrayZero  = [&](int k){
            vector<int>diffArray(n+1, 0);
            for(int i = 0; i<k; ++i){
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                diffArray[l] += val;
                diffArray[r+1] -= val;
            }
            int currVal = 0;
            for(int i = 0; i<n; ++i){
                currVal += diffArray[i];
                if(currVal<nums[i])return false;
            }
            return true;
        };
        if(all_of(nums.begin(), nums.end(), [](int x){return x == 0;}))return 0;
        int left = 1,  right = queries.size();
        if(!canMakeArrayZero(right))return -1;

        while(left<right){
            int mid = left + (right-left)/2;
            if(canMakeArrayZero(mid))right = mid;
            else left = mid+1;
        }

        return left;
    }
};