class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>st;
        int sum = 0;
        for(int num : nums){
            if(num>0){
                st.insert(num);
            }
        }
        if(st.empty())
                sum = *max_element(nums.begin(), nums.end());
        for(int val : st){
            sum += val;
        }
        return sum;
    }
};