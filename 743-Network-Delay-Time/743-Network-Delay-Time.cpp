class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
            vector<vector<pair<int, int>>>graph(n+1, vector<pair<int, int>>());
    
            for(auto& edge : times){
                graph[edge[0]].push_back(make_pair(edge[1], edge[2]));
            }
    
            vector<int>time(n+1, INT_MAX);
            priority_queue<pair<int, int>, 
                vector<pair<int, int>>, 
                greater<pair<int,int>>> pq;
    
           
            pq.push(make_pair(0, k));
            time[k] = 0;
            while(!pq.empty()){
                int u = pq.top().second;
                int delay = pq.top().first;
                pq.pop();
    
                for(auto& ne: graph[u]){
                    int v = ne.first;
                    int wt = ne.second;
                    if(wt + delay < time[v]){
                        time[v] = wt + delay;
                        pq.push(make_pair(time[v], v));
                    }
                }
            }
            int res = 0;
            for(int i = 1; i<=n; ++i){
                res = max(res, time[i]);
            }
            return (res == INT_MAX) ? -1 : res;
        }
    };