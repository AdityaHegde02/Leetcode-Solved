class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int p1 = INT_MAX, p2 = INT_MAX, p3 = INT_MAX;
        
        for(int i = 0; i < n; i++){
            if(p1 == INT_MAX){
                p1 = nums[i];
            }
            else if(p2 == INT_MAX and nums[i] > p1){
                p2 = nums[i];
            }
            else if(p3 == INT_MAX and nums[i] > p2){
                return true;
            }
            else if(p1 != INT_MAX and nums[i] < p1){
                p1 = nums[i];
            }
            else if(p2 != INT_MAX and p2 > nums[i] and p1 < nums[i]){
                p2 = nums[i];
            }
        }
        return (p3 == INT_MAX) ? (false) : (true);
    }
};