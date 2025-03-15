class Solution {
    bool canStealKHouses(vector<int>&nums, int capability, int k){
        int count =  0;
        for(int i = 0; i<nums.size(); ++i){
            if(nums[i]<=capability){
                ++count;
                ++i;
            }
        }
        return count>=k;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());

        while(left<right){
            int mid = left + (right-left)/2;
            if(canStealKHouses(nums, mid, k))
                right  = mid;
            else
                left = mid+1;
        }
        return left;
    }
};