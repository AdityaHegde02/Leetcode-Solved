class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int,int>freq;
        priority_queue<pair<int,int>>pq;
        vector<int>a;
        
        for(int i = 0;i<nums.size();i++)
        {
           freq[nums[i]]++;
        } 
        
        for(auto x : freq)
        {
            pq.push(make_pair(x.second,x.first));
        }
    
        for(int i = 0;i<k;i++)
        {
            a.push_back(pq.top().second);
            pq.pop();
        }
        
        return a;
    }
};