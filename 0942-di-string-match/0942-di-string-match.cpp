class Solution {
public:
    vector<int> diStringMatch(string s) {
        int sz = s.size();
        vector<int> permutation(sz + 1,0);
        int high = sz;
        map<int,vector<int>> mp;
        mp[0].push_back(0);
        int level = 0;
        for(int i = 0; i < sz; i++){
            if(s[i] == 'D'){
                level++;
                mp[level].push_back(i + 1);
            }
            else{
                level--;
                mp[level].push_back(i + 1);
            }
        }
        
        for(auto &p : mp){
            for(auto &i : p.second){
                permutation[i] = high--;
            }
        }
        return permutation;
    }
};