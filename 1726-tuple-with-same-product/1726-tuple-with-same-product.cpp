class Solution {
public:
    int nCr(int n, int r){
        if (r > n)
             return 0;
        if (r == 0 || r == n)
            return 1;
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
    
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        
        int ans = 0;
        for(auto &i : mp){
            if(i.second > 1){
                ans += nCr(i.second,2)*8;
            }
        }
        return ans;
    }
};