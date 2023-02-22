class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> mxHeap(nums.begin(),nums.end());
        while(k--){
            score += mxHeap.top();
            mxHeap.push(ceil((mxHeap.top()/3.0)));
            mxHeap.pop();
        }
        return score;
    }
};