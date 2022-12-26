class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<char> st;
        int bal = 0;
        int i = 0;
        while(i < n and (s[i] == ')')){
            i++;
        }
        if(i == n){
            return "";
        }
        if(s[i] == '('){
            bal++;
        }
        st.push(s[i]);
        i++;
        while(i < n and !st.empty()){
            if(s[i] == '('){
                bal++;
            }
            else if(s[i] == ')'){
                if(bal == 0){
                    i++;
                    continue;
                }
                else{
                    bal--;
                }
            }
            st.push(s[i++]);
        }
        
        string a = "";
        while(!st.empty()){
            if(bal and st.top() == '('){
                st.pop();
                bal--;
                continue;
            }
            a += st.top();
            st.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};