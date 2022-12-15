class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust){
        vector<int> x(n + 1,0),y(n + 1,0);
        for(auto &i : trust){
            x[i[0]]++;
            y[i[1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(x[i] == 0 and y[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};