class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maximums;
        
        deque<int> q;
        
        for(int i = 0 ; i < k ; i++){
            while(!q.empty() and nums[q.back()] < nums[i]){
                q.pop_back();
            }
            
            q.push_back(i);
        }
        
        maximums.push_back(nums[q.front()]);
        
        for(int i = k; i < n; i++){
            if(q.front() == i-k){
                q.pop_front();
            }
            
            while(!q.empty() and nums[q.back()] < nums[i]){
                q.pop_back();
            }
            
            q.push_back(i);
            maximums.push_back(nums[q.front()]);
        }
        
        return maximums;
    }
};