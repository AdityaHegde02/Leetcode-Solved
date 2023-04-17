class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size());
        int mx=INT_MIN;
        for(auto &i:candies){
           mx=max(mx,i);
        }

        for(int i=0;i<candies.size();i++){
            ans[i] = (candies[i]+extraCandies)>=mx;
        }
        return ans;
    }
};