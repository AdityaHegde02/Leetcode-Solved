class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 7 + 1e9,n = arr.size(),odds = 0, evens = 0,ans = 0;
        if(arr[0] % 2){
            ans++;
            odds++;
        }
        else{
            evens++;
        }
        for(int i = 1; i < n; i++){
            arr[i] += arr[i - 1];
            if(arr[i] % 2){
                ans = (ans + evens + 1) % mod;
                odds++;
            }
            else{
                ans = (ans + odds)% mod;
                evens++;
            }
        }
        
        return ans % mod;
    }
};