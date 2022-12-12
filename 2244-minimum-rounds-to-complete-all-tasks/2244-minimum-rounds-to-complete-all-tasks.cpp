class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size(),ans = 0;
        unordered_map<int,int> mp;
        for(auto &i : tasks){
            mp[i]++;
        }
        for(auto &pair:mp){
            if(pair.second == 1){
                return -1;
            }
            else if(pair.second % 3 == 0){
                ans += (pair.second)/3;
            }
            else if(pair.second % 3 == 1){
                int d = pair.second/3;
                ans += ((d-1)) + 2;
            }
            else if(pair.second % 3 == 2){
                ans += 1;
                pair.second -= 2;
                ans += (pair.second)/3;
            }
        }
        return ans;
    }
};