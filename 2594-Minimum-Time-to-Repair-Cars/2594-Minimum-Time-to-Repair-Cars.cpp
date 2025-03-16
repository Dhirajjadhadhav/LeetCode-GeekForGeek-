class Solution {
    bool canRepair(vector<int>&ranks, long long time, int cars){
        long long count = 0;
        for(int i = 0; i<ranks.size(); ++i){
            count += sqrt((time*1.0)/ranks[i]);
        }
        return count>=cars*1LL;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        
        long long low = 1;
        long long high = *max_element(ranks.begin(), ranks.end())*1LL*cars*cars; 
        long long ans = high;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(canRepair(ranks, mid, cars)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};