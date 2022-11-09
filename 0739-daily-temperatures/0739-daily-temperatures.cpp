class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> s;             // num,idx
        
        for(int i = 0; i < n; i++){
            while(!s.empty() and s.top().first < t[i]){
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({t[i],i});
        }
        
        return ans;
    }
};