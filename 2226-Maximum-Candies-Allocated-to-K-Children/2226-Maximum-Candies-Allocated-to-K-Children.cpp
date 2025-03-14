class Solution {
    bool canDivide(vector<int>&candies, long long k, long long val){
        for(int c : candies){
            k-=c/val;
            if(k<=0)return 1;
        }
        return 0;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if(sum<k)
            return 0;
        int l = 1, r = sum/k;
        while(l<r){
            int m = l + (r-l+1)/2;
            if(canDivide(candies, k, m))
                l = m;
            else
                r = m-1;
        }
        return l;
    }
};