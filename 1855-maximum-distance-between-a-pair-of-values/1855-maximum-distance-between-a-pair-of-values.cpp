class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int maxDiff = INT_MIN;
        
        if(nums1.back() > nums2[0]){
            return 0;
        }
        
        for(int i = 0; i < m; i++){
            int low = i;
            int high = n - 1;
            int idx = -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(nums2[mid] >= nums1[i]){
                    idx = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            if(idx != -1 and nums2[idx] >= nums1[i]){
                maxDiff = max(maxDiff,idx - i);
            }
        }
        
        return (maxDiff==INT_MIN) ? 0 : maxDiff;
    }
};