class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int noOfSubArrays = 0;
        unordered_map<int,int> mp;
        
        vector<int> prefix(n,0);
        
        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                prefix[i] = nums[i];
            }
            else{
                prefix[i] = prefix[i - 1] + nums[i];
            }
        }
        
        for(int i = 0; i < n; i++){
            if(prefix[i] == k){
                noOfSubArrays++;
            }
            if(mp.count(prefix[i] - k)){
                noOfSubArrays += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }
        
        return noOfSubArrays;
    }
};