class Solution {
public:
    typedef long long ll;
    bool isValid(ll target, vector<int>& nums){
        if(nums[0]>target) return false; 
        ll prev=nums[0];
        for(int i=1;i<nums.size();++i){
            ll diff=target-prev; 
            prev=nums[i]-diff; 
            if(prev>target) return false; 
        }
        return true; 
    }

    int minimizeArrayValue(vector<int>& nums) {
        ll left=0, right=*max_element(nums.begin(),nums.end()); 
        while(left<right){ 
            int mid=left+(right-left)/2; 
            if(isValid(mid,nums)) right=mid; 
            else left=mid+1; 
        }
        return right; 
    }
};