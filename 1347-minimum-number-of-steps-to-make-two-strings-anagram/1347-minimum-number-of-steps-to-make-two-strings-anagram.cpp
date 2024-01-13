class Solution {
public:
    int minSteps(string s, string t) {
        int m=s.size(),n=t.size();
        unordered_map<char,int> a;
        unordered_map<char,int> b;
        for(int i=0;i<m;i++){
            a[s[i]]++;
        }
        for(int i=0;i<n;i++){
            b[t[i]]++;
        }
        
        int ans=0;
        
        for(int i=0;i<m;i++){
            if(b[t[i]]>0 and a[t[i]]==0){
                ans+=1;
                b[t[i]]--;
                
            }
            else if(b[t[i]]>a[t[i]]){
                b[t[i]]--;
                a[t[i]]--;
            }
        }
        return ans;
    }
};