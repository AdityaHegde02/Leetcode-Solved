class Solution {
public:
    string simplifyPath(string s) {
        int n = s.size();
        string ans;
        stack<string> st;
        
        for(int i = 0; i < n; ){
            if(s[i] == '/'){
                i++;
                string temp = "";
                while(i < n and s[i] != '/'){
                    temp += s[i++];
                }
                
                if(temp == ".."){
                    if(!st.empty()){
                        st.pop();
                    }
                }
                
                else if(temp == "." or temp == ""){
                    continue;
                }
                
                else{
                    st.push(temp);
                }
            }
        }
        
        vector<string> words;
        
        while(!st.empty()){
            words.push_back(st.top());
            st.pop();
        }
        
        for(int i = words.size() - 1; i >= 0; i--){
            ans += '/';
            ans += words[i];
        }
        
        if(ans == ""){
            ans += '/';
        }
        
        return ans;
    }
};