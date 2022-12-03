class Solution {
public:
    void solve(int n,string &temp,string &tiles,unordered_set<string> &s,vector<int> &visited){
        if(temp.size() and s.find(temp) == s.end()){
            s.insert(temp);
        }
        
        for(int j = 0; j < n; j++){
            if(!visited[j]){
                visited[j] = 1;
                temp += tiles[j];
                solve(n,temp,tiles,s,visited);
                temp.pop_back();
                solve(n,temp,tiles,s,visited);
                visited[j] = 0;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        unordered_set<string> s;

        for(int i = 0; i < n; i++){
            vector<int> visited(n,0);
            string temp;
            temp += tiles[i];
            visited[i] = 1;
            solve(n,temp,tiles,s,visited);
        }
    
        return s.size();
    }
};