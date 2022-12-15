class Solution {
public:
    unordered_set<int> keys;
    
    void solve(int i,int n,vector<vector<int>> &rooms){
        if(i >= n or keys.size() == n){
            return ;
        }
        
        keys.insert(i);
        
        for(auto &k : rooms[i]){
            if(keys.find(k) == keys.end()){
                keys.insert(k);
                solve(k,n,rooms);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        solve(0,n,rooms);
        return (keys.size() == n);
    }
};