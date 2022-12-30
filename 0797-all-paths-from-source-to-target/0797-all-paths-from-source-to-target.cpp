class Solution {
public:
    void getPaths(int i,int n,vector<vector<int>>& graph,vector<vector<int>> &paths,vector<int> &temp){
        
        temp.push_back(i);
        
        if(i==n-1){
            paths.push_back(temp);
            temp.pop_back();
            return ;
        }
        
        for(auto &j:graph[i]){
            getPaths(j,n,graph,paths,temp);
        }
        
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> paths;
        vector<int> temp;
        getPaths(0,n,graph,paths,temp);
        return paths;
    }
};