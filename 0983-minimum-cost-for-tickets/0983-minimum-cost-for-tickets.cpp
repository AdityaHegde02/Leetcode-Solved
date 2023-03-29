class Solution {
public:
    long long int dp[366][31][1001];
    
    int solve(int idx,int prev,int prevDay,vector<int> &days,vector<int> &costs){
        if(idx >= days.size()){
            return 0;
        }    
        
        if(prev != -1 and dp[idx][prev][prevDay] != -1){
            return dp[idx][prev][prevDay];
        }
        
        if((prev == -1 and prevDay == -1) or prev == 1){
            long long int a = costs[0] + solve(idx + 1,1,days[idx],days,costs);
            long long int b = costs[1] + solve(idx + 1,7,days[idx],days,costs);
            long long int c = costs[2] + solve(idx + 1,30,days[idx],days,costs);
            return (long long)min({a,b,c});
        }
        
        else if(prev == 7){
            if(days[idx] - prevDay >= 7){
              long long int a = costs[0] + solve(idx + 1,1,days[idx],days,costs);
              long long int b = costs[1] + solve(idx + 1,7,days[idx],days,costs);
              long long int c = costs[2] + solve(idx + 1,30,days[idx],days,costs);
                return dp[idx][prev][prevDay] = min({a,b,c});
            }
            else{
                return dp[idx][prev][prevDay] = solve(idx + 1,prev,prevDay,days,costs);
            }
        }
        
        else{
            if(days[idx] - prevDay >= 30){
                int a = costs[0] + solve(idx + 1,1,days[idx],days,costs);
                int b = costs[1] + solve(idx + 1,7,days[idx],days,costs);
                int c = costs[2] + solve(idx + 1,30,days[idx],days,costs);
                return dp[idx][prev][prevDay] = (long long)min({a,b,c});
            }
            else{
                return dp[idx][prev][prevDay] = (long long)solve(idx + 1,prev,prevDay,days,costs);
            }
        }
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,-1,days,costs);
    }
};