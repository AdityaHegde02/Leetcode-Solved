class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int m = p.size(), n = t.size();
        sort(p.begin(),p.end());
        sort(t.begin(),t.end());
        int i = 0, j = 0, ans = 0;
        while(i < m and j < n){
            while(j < n and t[j] < p[i]){
                j++;
            }
            if(j < n){
                ans++;
            }
            i++;
            j++;
        }
        return ans;
    }
};