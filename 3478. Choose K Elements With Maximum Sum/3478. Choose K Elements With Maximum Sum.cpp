class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
           
            vector<long long>ans(nums1.size());
    
            vector<pair<int, pair<int, int>>>arr;
    
            for(int i = 0; i<nums1.size(); ++i){
                arr.push_back({nums1[i],{nums2[i], i}});
            }
    
            sort(arr.begin(), arr.end());
            priority_queue<int, vector<int>, greater<int>>pq;
            long long sum = 0;
            int prevVal = 0;
            long long prevSum = 0;
            for(auto it : arr){
                if(it.first == prevVal)
                    ans[it.second.second] = prevSum;
                else
                {
                      ans[it.second.second] = sum;
                      prevSum = sum;
                }
                pq.push(it.second.first);
                sum += it.second.first;
                if(pq.size()>k){
                    sum-= pq.top();
                    pq.pop();
                }
                prevVal = it.first;
                
            }
    
            return ans;
        }
    };