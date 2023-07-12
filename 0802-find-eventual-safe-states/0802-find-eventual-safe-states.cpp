class Solution {
public:
    bool cycle(int i,vector<int> &vis,vector<vector<int>>& graph,vector<int> &pathVis,vector<int> &cyc){
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto &neg : graph[i]){
            if(!vis[neg]){
                if(cycle(neg,vis,graph,pathVis,cyc)){
                    cyc[i] = 1;
                    return true;
                }
            }
            if(pathVis[neg]){
                cyc[i] = 1;
                return true;
            }
        }
        pathVis[i] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans,vis(n,0),pathVis(n,0),cyc(n,0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                cycle(i,vis,graph,pathVis,cyc);
            }
        }
        for(int i = 0; i < n; i++){
            if(!cyc[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};