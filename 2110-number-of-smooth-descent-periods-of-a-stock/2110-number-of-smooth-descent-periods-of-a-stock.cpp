class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        for(int i = 0; i < prices.size(); i++){
            long long len = 1;
            while(i + 1 < prices.size() and prices[i] == prices[i + 1] + 1){
                len++;
                i++;
            }
            ans += ((long long)len*(len + 1))/2;
        }
        return ans;
    }
};