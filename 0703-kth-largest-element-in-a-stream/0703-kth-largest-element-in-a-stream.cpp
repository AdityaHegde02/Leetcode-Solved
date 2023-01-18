class KthLargest {
public:
    int K;
    vector<int> sorted;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        sort(nums.begin(),nums.end());
        sorted = nums;
    }
    
    int add(int val) {
        auto pos = lower_bound(sorted.begin(),sorted.end(),val);
        sorted.insert(pos, val);
        return sorted[sorted.size() - K];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */