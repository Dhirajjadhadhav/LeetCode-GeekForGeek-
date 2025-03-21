class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            
            unordered_map<string, vector<string>>graph;
            unordered_map<string, int>indegree;
    
            for(int i = 0; i<recipes.size(); ++i){
                for(auto& ing : ingredients[i]){
                    graph[ing].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
    
            queue<string>q;
            for(auto& s : supplies)
                q.push(s);
    
            unordered_set<string>made;
            while(!q.empty()){
                string curr = q.front();
                q.pop();
                for(auto& next : graph[curr]){
                    if(--indegree[next] == 0){
                        q.push(next);
                        made.insert(next);
                    }
                }
            }
    
            vector<string>result;
            for(auto& r : recipes){
                if(made.count(r))
                    result.push_back(r);
            }
    
            return result;
        }
    };