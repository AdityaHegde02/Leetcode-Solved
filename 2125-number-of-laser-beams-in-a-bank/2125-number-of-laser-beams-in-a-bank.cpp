class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        vector<int> a;
        int m=b.size();
        int n=b[0].size();
        
        if(m==1){
            return 0;
        }
        
        for(int i=0;i<m;++i){
            int count=0;
            for(int j=0;j<n;++j){
                if(b[i][j]=='1'){
                    count++;
                }
            }
            if(count){
                a.push_back(count);
            }
        }
        
        if(a.size()<=1){
            return 0;
        }
        
        int ans=0;
        
        for(int i=0;i<a.size()-1;++i){
            int p=(a[i]*a[i+1]);
            ans+=p;
        }
        
        return ans;
    }
};