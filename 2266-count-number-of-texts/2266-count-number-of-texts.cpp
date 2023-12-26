class Solution {
public:
    int mod = 1e9 + 7;
    int dp[11][100001];
    
    long long solve(int num,int times){
        // cout << times << endl;
        if(times <= 0){
            return 1;
        }
        
        if(dp[num][times] != -1){
            return dp[num][times];
        }
        
        if(num == 7 or num == 9){           // take 4 times also
            if(times == 1){
                return 1;
            }
            else if(times == 2){
                return 2;
            }
            else if(times == 3){
                return 4;
            }
            else if(times == 4){
                return 8;
            }
            else{
                long long x = 1, y = 1, z = 1, zz = 1;
                // take 1
                x = solve(num,times - 1) % mod;
                
                // take 2
                y = solve(num,times - 2) % mod;
                
                // take 3
                z = solve(num,times - 3) % mod;
                
                zz = solve(num,times - 4) % mod;
                
                return dp[num][times] = ((x + y + z + zz) % mod);
            }
        }
        else{                               // no 4 times
            if(times == 1){
                return 1;
            }
            else if(times == 2){
                return 2;
            }
            else if(times == 3){
                return 4;
            }
            else{
                long long x = 1, y = 1, z = 1;
                // take 1
                x = solve(num,times - 1) % mod;
                
                // take 2
                y = solve(num,times - 2) % mod;
                
                // take 3
                z = solve(num,times - 3) % mod;
                
                return dp[num][times] = ((x+y+z) % mod);
            }
        }
        
        return 0;
    }
    
    int countTexts(string pressedKeys) {
        long long n = pressedKeys.size(), i = 0, j = 0, ans = 1;
        memset(dp,-1,sizeof(dp));
        
        while(true){
            if(i >= n){
                break;
            }
            
            char c = pressedKeys[i];
            while( j < n and pressedKeys[j] == c){
                j++;
            }
            
            int mul = solve(c - '0', j - i);
            
            ans = (ans*mul) % mod;
            
            i = j;
        }
        
        return ans % mod;
    }
};