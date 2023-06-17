class Solution {
public:
    int dp[2001][2001][2];
    
    int solve(int idx,int prevIdx,bool isChanged,vector<int>& arr1, vector<int>& arr2){
        if(idx >= arr1.size()){
            return 0;
        }
        
        if(isChanged == true and prevIdx >= arr2.size()){
            return -1;
        }
        
        if(prevIdx >= 0 and dp[idx][prevIdx][isChanged] != INT_MAX){
            return dp[idx][prevIdx][isChanged];
        }
        
        int prev;
        if(prevIdx == -1){
            prev = -1;
        }
        else if(isChanged){
            prev = arr2[prevIdx];
        }
        else{
            prev = arr1[prevIdx];
        }
        
        int i = upper_bound(arr2.begin(),arr2.end(),prev) - arr2.begin();
        
        if(prev >= arr1[idx]){      // should change
        
            if(i >= arr2.size()){
                return dp[idx][prevIdx][isChanged] = -1;
            }
            
            int ops = solve(idx + 1,i,true,arr1,arr2);
            if(ops == -1){
                return dp[idx][prevIdx][isChanged] = -1;
            }
            return dp[idx][prevIdx][isChanged] = 1 + ops;
        }
        
        int ops2 = solve(idx + 1,idx,false,arr1,arr2);   // no change
       
        if(i >= arr2.size() and ops2 == -1){
            return dp[idx][prevIdx][isChanged] = -1;
        }
        else if(i >= arr2.size()){
            return dp[idx][prevIdx][isChanged] = ops2;
        }
        
        int ops1 = solve(idx + 1,i,true,arr1,arr2);    // change
        
        if(ops1 == -1 and ops2 == -1){
            if(prevIdx == -1){
                return -1;
            }
            return dp[idx][prevIdx][isChanged] = -1;
        }
        else if(ops1 == -1){
            if(prevIdx == -1){
                return ops2;
            }
            return dp[idx][prevIdx][isChanged] = ops2;
        }
        else if(ops2 == -1){
            if(prevIdx == -1){
                return 1 + ops1;
            }
            return dp[idx][prevIdx][isChanged] = 1 + ops1;
        }
        
        if(prevIdx == -1){
            return min(1 + ops1,ops2);
        }

        return dp[idx][prevIdx][isChanged] = min(1 + ops1,ops2);
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        for(int i = 0; i < 2001; i++){
            for(int j = 0; j < 2001; j++){
                for(int k = 0; k < 2; k++){
                    dp[i][j][k] = INT_MAX;
                }
            }
        }
        int ops = solve(0,-1,false,arr1,arr2);
        return (ops == -1)?-1:ops;
    }
};