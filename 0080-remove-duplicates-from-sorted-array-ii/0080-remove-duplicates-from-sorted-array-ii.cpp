class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        
        for(int &i : nums){
            mp[i]++;
        }
        
        int j = 0;
        int len = 0;
        for(auto &i : mp){
            if(i.second >= 2){
                nums[j++] = i.first;
                nums[j++] = i.first;
                len += 2;
            }
            else{
                nums[j++] = i.first;
                len++;
            }
        }
        
        return len;
    }
};