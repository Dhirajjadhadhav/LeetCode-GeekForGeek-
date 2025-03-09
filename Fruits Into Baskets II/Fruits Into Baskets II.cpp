class Solution {
    public:
        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            
            int n = fruits.size();
            vector<bool>vis(n, false);
    
            for(int i = 0; i<n; ++i){
                for(int j = 0; j<n; ++j){
                    if(!vis[j] && fruits[i]<=baskets[j]){
                       
                        vis[j] = true;
                        break;
                    }
                }
            }
            int cnt = 0;
            for(int i = 0; i<n; ++i){
                 if(!vis[i])
                        ++cnt;
            }
            return cnt;
        }
    };