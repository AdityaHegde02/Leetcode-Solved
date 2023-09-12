class Solution {
public:
    int minDeletions(string s) {
        int del = 0;
        int n = s.size();
        
        vector<int> mp(26,0);
        for(char &c:s){
            mp[c-'a']++;
        }
        
        sort(mp.rbegin() , mp.rend());
        
        set<int> st;
        
        for ( int i = 0 ; i < 26 ; i++){
            
            if( mp[i]==0 ){
                break;
            }
            
            if( mp[i]!=0 and st.count(mp[i])==0 ){
                st.insert( mp[i] );
            }
            
            else if( st.count(mp[i]) ){
                while( st.count(mp[i]) and mp[i]>=0 ){
                    mp[i]--;
                    del++;
                }
                if( mp[i] ){
                    st.insert( mp[i] );
                }
            }
            
        }
        return del;
    }
};