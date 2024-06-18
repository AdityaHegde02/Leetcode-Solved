class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        int n = d.size(), m = w.size(), mx = 0;
        vector<pair<int,int>> pi;
        for(int i = 0; i < n; i++){
            pi.push_back({d[i],p[i]});
        }
        
        sort(pi.begin(),pi.end());
        sort(w.begin(),w.end());
        
        int currmx = 0, j = 0;
        for(int i = 0; i < m; i++){
            while(j < n and pi[j].first <= w[i]){
                currmx = max(currmx,pi[j].second);
                j++;
            }
            mx += currmx;
        }
        return mx;
    }
};