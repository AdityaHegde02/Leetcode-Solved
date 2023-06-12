class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        int n = nums.size();
        
        for(int i = 0; i < n;){
            int first = nums[i],last = nums[i],cnt = 0;
            while(i < n and nums[i] == cnt + first){
                last = nums[i];
                i++;
                cnt++;
            }
            
            if(first == last){
                ans.push_back(to_string(first));
            }
            else{
                string a = to_string(first);
                a += "->";
                a += to_string(last);
                ans.push_back(a);   
            }
        }
        
        return ans;
    }
};