class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // line sweep method
        vector<int> line(1000002,0);
        for(auto &i : intervals){
            line[i[0]]++;
            line[i[1] + 1]--;
        }
        
        int mx = 0, curr = 0;
        for(auto &i : line){
            curr += i;
            mx = max(mx,curr);
        }
        
        return mx;
    }
};