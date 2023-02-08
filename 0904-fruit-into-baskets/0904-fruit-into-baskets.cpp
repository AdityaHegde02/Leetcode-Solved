class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mp;
        int i = 0, j = 0, ans = 0;
        
        while(j < n){
            if(mp.find(fruits[j]) == mp.end()){
                if(mp.size() < 2){
                    mp[fruits[j]]++;
                }
                else{
                    break;
                }
            }
            else{
                mp[fruits[j]]++;
            }
            j++;
        }
        ans = max(ans, j - i);
        
        while(i < n and j < n){
            while(mp.size() == 2){
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            while(j < n){
                if(mp.find(fruits[j]) == mp.end()){
                    if(mp.size() < 2){
                        mp[fruits[j]]++;
                    }
                    else{
                        break;
                    }
                }
                else{
                    mp[fruits[j]]++;
                }
                j++;
            }
            ans = max(ans,j - i);
        }
        return ans;
    }
};