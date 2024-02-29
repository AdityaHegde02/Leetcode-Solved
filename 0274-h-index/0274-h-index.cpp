class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());
        int n = c.size(), ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,min(n - i,c[i]));
        }
        return ans;
    }
};