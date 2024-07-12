class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size(), ans = 0, i = 0;
        stack<char> st;
        if(x >= y){
            // need "ab" first
            while(i < n){
                int a = 0,b = 0;
                while(i < n and (s[i] == 'a' or s[i] == 'b')){
                    if(s[i] == 'b'){
                        if(!st.empty() and st.top() == 'a'){
                            st.pop();
                            ans += x;
                            a--;
                        }
                        else{
                            st.push(s[i]);
                            b++;
                        }
                    }
                    else{
                        st.push(s[i]);
                        a++;
                    }
                    i++;
                }
                while(!st.empty()){
                    st.pop();
                }
                int ba = min(a,b);
                ans += y*ba;
                i++;
            }
            return ans;
        }
        // need "ba" first
            while(i < n){
                int a = 0,b = 0;
                while(i < n and (s[i] == 'a' or s[i] == 'b')){
                    if(s[i] == 'a'){
                        if(!st.empty() and st.top() == 'b'){
                            st.pop();
                            ans += y;
                            b--;
                        }
                        else{
                            st.push(s[i]);
                            a++;
                        }
                    }
                    else{
                        st.push(s[i]);
                        b++;
                    }
                    i++;
                }
                while(!st.empty()){
                    st.pop();
                }
                int ba = min(a,b);
                ans += x*ba;
                i++;
            }
            return ans;
    }
};