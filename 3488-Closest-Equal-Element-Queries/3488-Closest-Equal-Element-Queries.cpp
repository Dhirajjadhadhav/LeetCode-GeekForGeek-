class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, int>first, last;
        vector<int>closest(n, -1);

        //loop for checking the next closest 
        for(int i = 0; i<n; ++i){
           if(first.count(nums[i]) == 0){
                first[nums[i]] = i;
           } 
           else
           {
             int j = last[nums[i]];
             setClosest(i, i-j,closest);
             setClosest(j, i-j, closest);
           }
           last[nums[i]] = i;
        }

        //loop to check circular closest
        for(auto[num, i] : last){
            int j = first[num];
            if(i != j){
                setClosest(i, n+j-i, closest);
                setClosest(j, n + j-i, closest);
            }
        }

        vector<int>res;
        for(int q : queries){
            res.push_back(closest[q]);
        }
        return res;
    }
private:
    void setClosest(int pos, int val, vector<int>&closest){
        if(closest[pos] == -1)
            closest[pos] = val;
        else
            closest[pos] = min(closest[pos], val);
    }
};