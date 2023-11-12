class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>>bStopToBIds;
      
        for(int i = 0; i<routes.size(); ++i)
        {
            for(const auto&  bus: routes[i])
            {
                bStopToBIds[bus].push_back(i);
            }
        }
        
        queue<pair<int, int>>q;
        unordered_map<int, bool>bVis, bStopVis;
        
        q.push({source, 0});
        bStopVis[source] = true;
        while(!q.empty()){
            int sz = q.size();
            while(sz--)
            {
                pair<int, int>p = q.front();
                q.pop();
                int curStop = p.first;
                int busTravelled = p.second;
                if(curStop == target)
                    return busTravelled;
                for(auto bus:bStopToBIds[curStop]){
                    if(bVis[bus])continue;
                    bVis[bus] = true;
                    for(auto busStop:routes[bus])
                    {
                        if(bStopVis[busStop])continue;
                        q.push({busStop, busTravelled+1});
                        bStopVis[busStop] = true;
                    }
                }
            }
        }
        return -1; 
    }
};