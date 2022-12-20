class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> keys;
        queue<int> q;
        for(int &i : rooms[0]){
            q.push(i);
        }
        keys.insert(0);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                int currKey = q.front();
                q.pop();
                keys.insert(currKey);
                for(int &j : rooms[currKey]){
                    if(keys.count(j) == 0){
                        q.push(j);
                    }
                }
            }
        }
        return (keys.size() == n);
    }
};