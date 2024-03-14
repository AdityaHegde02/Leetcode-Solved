class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal == 0){
            int cnt = 0, ans = 0;
            for(auto &i : nums){
                if(i == 0){
                    cnt++;
                }
                else{
                    ans += (cnt)*(cnt + 1)/2;
                    cnt = 0;
                }
            }
            if(cnt){
                ans += (cnt)*(cnt + 1)/2;
            }
            return ans;
        }
        int o = 0, ans = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(auto &i : nums){
            o += (i == 1);
            mp[o]++;
        }
        
        // cout << mp.size();

        for(auto &i : mp){
            int need = i.first + goal;
            if(mp.count(need))
                ans += (mp[need]*(i.second));
        }
        
        return ans;
    }
};