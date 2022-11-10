class Solution {
public:
    static bool cmp(int& a,int& b){
        string s = to_string(a);
        string t = to_string(b);
        return (s < t);
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        for(int i = 1; i <= n; i++){
            ans[i - 1] = i;
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};