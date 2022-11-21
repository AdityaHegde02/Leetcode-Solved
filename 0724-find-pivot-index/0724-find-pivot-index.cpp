class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);

        for(int i = 0 ; i < n; i++){
            if(i == 0){
                prefix[i] = nums[i];
            }
            else{
                prefix[i] = prefix[i - 1] + nums[i];
            }
        }

        if(prefix[n - 1] - prefix[0] == 0 ){
            return 0;
        }

        for(int i = 1; i < n - 1; i++){
            if(prefix[i - 1] == prefix[n - 1] - prefix[i]){
                return i;
            }
        }

        if(prefix[n - 2] == 0){
            return n - 1;
        }
        
        return -1;
    }
};