class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        k--;
        for(auto &i : nums){
            maxHeap.push(i);
        }
        
        while(k--){
            auto f = maxHeap.top();
            maxHeap.pop();
        }
        
        return maxHeap.top();
    }
};