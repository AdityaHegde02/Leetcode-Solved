class Solution {
public:
    vector<int> relativeSortArray(vector<int>& a, vector<int>& b) {
        map<int,int> mp;
        for(int i:a){
            mp[i]++;
        }
        int j=0;
        for(int &i:b){
            while(mp[i]>0){
                a[j]=i;
                mp[i]--;
                j++;
            }
        }
        
        for(auto &i:mp){
            while(i.second>0){
                a[j]=i.first;
                i.second--;
                j++;
            }
        }
        return a;
    }
};