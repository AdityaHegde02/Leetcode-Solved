class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        vector<pair<int,int>> mxright(n),mnright(n);
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1){
                mxright[i].first = mnright[i].first = nums[i];
                mxright[i].second = mnright[i].second = i;
            }
            else{
                mxright[i].first = max(nums[i],mxright[i + 1].first);
                mnright[i].first = min(nums[i],mnright[i + 1].first);
                if(mxright[i].first == nums[i]){
                    mxright[i].second = i;
                }
                else{
                    mxright[i].second = mxright[i + 1].second;
                }
                if(mnright[i].first == nums[i]){
                    mnright[i].second = i;
                }
                else{
                    mnright[i].second = mnright[i + 1].second;
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(i + indexDifference < n){
                int d1 = abs(nums[i] - mnright[i + indexDifference].first), d2 = abs(nums[i] - mxright[i + indexDifference].first);
                if(d1 >= valueDifference){
                    return {i,mnright[i + indexDifference].second};
                }
                if(d2 >= valueDifference){
                    return {i,mxright[i + indexDifference].second};
                }
            }
        }
                   
        return {-1,-1};
    }
};