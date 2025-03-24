class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>mp;
        stack<int>st;
        for(int i = 0; i<nums2.size(); ++i){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                mp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        vector<int>res;
        for(auto& it : nums1){
            if(mp.count(it)){
                res.push_back(mp[it]);
            }
            else
                res.push_back(-1);
        }
        return res;
    }
};