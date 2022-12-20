class Solution {
public:
    int findLucky(vector<int>& arr) {
        int l = -1;
        unordered_map<int,int> freq;
        for(auto &i : arr){
            freq[i]++;
        }
        for(auto &p : freq){
            if(p.first == p.second){
                l = max(l,p.first);
            }
        }
        return l;
    }
};