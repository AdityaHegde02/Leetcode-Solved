class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int m = s1.size(),n = s2.size();
        if(m < n){
            swap(s1,s2);
            swap(m,n);
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            string temp = s2.substr(0,i + 1);
            int sz = temp.size();
            if(m % sz != 0){
                continue;
            }
            bool ok = 1;
            for(int j = 0; j < m; j += sz){
                string x = s1.substr(j,sz);
                if(x != temp){
                    ok = 0;
                    break;
                }
            }
            
            for(int j = 0; j < n; j += sz){
                string x = s2.substr(j,sz);
                if(x != temp){
                    ok = 0;
                    break;
                }
            }
            
            if(ok){
                ans = temp;
            }
            
        }
        return ans;
    }
};