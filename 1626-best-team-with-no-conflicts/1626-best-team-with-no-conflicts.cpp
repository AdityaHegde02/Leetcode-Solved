class Solution {
public:
    int solve(int i,vector<pair<int,int>> &ageScores,int prevAge,vector<vector<int>> &dp){
        if(i >= ageScores.size()){
            return 0;
        }
        
        if(dp[i][prevAge] != -1){
            return dp[i][prevAge];
        }
        
        int temp = 0;
        if(ageScores[i].second >= prevAge){
            temp = max(temp,ageScores[i].first + solve(i + 1,ageScores,ageScores[i].second,dp));
        }
        
        temp = max(temp, solve(i + 1,ageScores,prevAge,dp));
        
        return dp[i][prevAge] = temp;
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> ageScores;
        for(int i = 0; i < ages.size(); i++){
            ageScores.push_back({scores[i],ages[i]});
        }
        sort(ageScores.begin(),ageScores.end(),[&](auto &a,auto &b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        vector<vector<int>> dp(1001,vector<int> (1001,-1));
        return solve(0,ageScores,0,dp);
    }
};