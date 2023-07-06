class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minSize = INT_MAX ;
        int currSum = 0 ;
        
        vector<int> prefixSum(n+1,0);
        
        for(int i=1;i<=n;i++){
            prefixSum[i] = prefixSum[i-1]+nums[i-1];
        }
        
        for(int i = 0 ; i < n + 1 ;i++ ){
            int curr = prefixSum[i];
            if(curr == target){
                minSize = min(minSize,i+1);
            }
            int need = target + curr ;
            int start = i + 1;
            int end = n ;
            while( start <= end ){
                int mid = start + (end-start)/2;
                if( prefixSum[mid] == need){
                    minSize = min(minSize,mid-i);
                    break;
                }
                else if(prefixSum[mid] > need){
                    minSize = min(minSize,mid-i);
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
             
            }
        }
        
        return (minSize==INT_MAX)?0:minSize;
    }
};