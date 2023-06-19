class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0,mx = 0;
        for(int i = 0; i < gain.size(); ++i){
            curr += gain[i];
            mx = max(mx,curr);
        }
        return mx;
    }
};