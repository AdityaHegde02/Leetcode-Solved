class Solution {
public:
    int getMax(string s){
        stringstream a(s);
        string b;
        int mx = 0;
        while(a >> b){
            int n = b.length();
            mx = max(mx,n);
        }
        return mx;
    }
    
    vector<string> printVertically(string s) {
        int n = s.size();
        int mxLen = getMax(s);
        vector<string> ans(mxLen);
        
        stringstream a(s);
        string b;
        
        while(a >> b){
            int i = 0;
            int j = 0;
            while(j < b.size()){
                ans[i++] += b[j++];
            }
            while(i < mxLen){
                ans[i++] += ' ';
            }
        }
        
        for(int i = mxLen - 1; i >= 0 ; i--){
            while(ans[i].back() == ' '){
                ans[i].pop_back();
            }
        }
        
        return ans;
    }
};