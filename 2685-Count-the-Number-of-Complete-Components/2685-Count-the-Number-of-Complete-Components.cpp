class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            
            vector<vector<int>>graph(n, vector<int>());
            vector<int>indegree(n, 0);
            vector<bool>vis(n);
            int res = 0;
            for(auto edge : edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
                indegree[edge[0]]++;
                indegree[edge[1]]++;
            }
    
            for(int i = 0; i<n; ++i){
              
                if(vis[i])continue;
                queue<int>q;
                q.push(i);
                vector<int>comp;
    
                while(!q.empty()){
                    int node = q.front();
                    comp.push_back(node);
                    q.pop();
                    vis[node] = true;
                    for(auto& ne : graph[node]){
                        if(vis[ne])continue;
                        q.push(ne);
                        vis[ne] = true;
                    }
    
                }
                bool isComplete = true;
                int size = comp.size()-1;
               
                
                for(auto& it : comp){
                    if(indegree[it] != size){
                        isComplete = false;
                        break;
                    }
                }
                if(isComplete)++res;
            }
            return res;
        }
    };