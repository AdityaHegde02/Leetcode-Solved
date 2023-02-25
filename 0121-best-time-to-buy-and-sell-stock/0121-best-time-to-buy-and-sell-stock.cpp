class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size(),res =0,mn=prices[0];
    
        for(int i=1; i<n;i++) {
            mn=min(mn,prices[i]);
            res=max(res,prices[i]-mn);
        }
        
        return res;
    }
};