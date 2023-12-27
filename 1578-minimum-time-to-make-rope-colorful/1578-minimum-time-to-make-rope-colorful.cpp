class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), time = 0;
        for(int i = 0; i < n; ){
            char curr = colors[i];
            int mx = 0, sum = 0, cnt = 0;
            while(i < n and curr == colors[i]){
                sum += neededTime[i];
                mx = max(mx,neededTime[i]);
                i++;
                cnt++;
            }
            if(cnt != 1){
                time += (sum - mx);
            }
        }
        return time;
    }
};