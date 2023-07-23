class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> count(102,0);
        for(int i = 0; i < logs.size(); i++){
            for(int j = logs[i][0]; j < logs[i][1]; j++){
                count[j - 1950]++;
            }
        }
        
        int mx = 0,ans = 0;
        for(int i = 0; i < 102; i++){
            if(mx < count[i]){
                ans = i + 1950;
                mx = count[i];
            }
        }
        return ans;
    }
};