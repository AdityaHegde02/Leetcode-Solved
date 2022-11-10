class Solution {
public:
    string removeDuplicates(string s) {
        int n=s.length(),i=1;
        stack<char> st;
        st.push(s[0]);
        while(i!=n){
            if(st.size()!=0){
                char t=st.top();
                if(t!=s[i]){
                    st.push(s[i]);
                }
                if(t==s[i]){
                st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
            i++;   
        }
    
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};