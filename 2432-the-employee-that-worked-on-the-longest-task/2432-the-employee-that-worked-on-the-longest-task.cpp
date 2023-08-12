class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int prev = 0, mx = 0, id = INT_MAX;
        for(auto &i : logs){
            int diff = i[1] - prev;
            if(diff > mx){
                id = i[0];
                mx = diff;
            }
            else if(diff == mx){
                id = min(id,i[0]);
            }
            prev = i[1];
        }
        return id;
    }
};