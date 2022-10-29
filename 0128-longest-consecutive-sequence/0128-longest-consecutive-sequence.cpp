class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        
        for(auto &i : nums){
            s.insert(i);
        }
        
        int len = 0;
        int currLen = 0;
        for(int i = 0; i < n; i++){
            if(s.count(nums[i] - 1)){
                continue;
            }
            else{
                currLen = 1;
                int j = 1;
                while(s.count(nums[i] + j++)){
                    currLen++;
                }
                len = max(currLen,len);
            }
        }
        
        return len;
    }
};