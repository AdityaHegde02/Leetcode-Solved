class Solution {
public:
    static bool mycmp(const pair<char,int> &a,const pair<char,int> &b){
        return (a.second>b.second);
    }
    
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<pair<char,int>> a;
        for(auto i:mp){
            a.push_back({i.first,i.second});
        }
        sort(a.begin(),a.end(),mycmp);
        string ans="";
        for(int i=0;i<a.size();i++){
            while(a[i].second){
                ans+=a[i].first;
                a[i].second--;
            }
        }
        return ans;
    }
};