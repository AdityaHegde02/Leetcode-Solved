class Solution {
public:
    int evalRPN(vector<string>& t) {
        int n = t.size();
        stack<int> st;
        for(auto &s : t){
            if(st.empty()){
                st.push(stoi(s));
            }
            else{
                if(s != "+" and s != "-" and s!= "*" and s != "/"){
                    st.push(stoi(s));
                }
                else{
                    int y = st.top();
                    st.pop();
                    int x = st.top();
                    st.pop();
                    if(s == "+"){
                        st.push(x+y);
                    }
                    else if(s == "-"){
                        st.push(x-y);
                    }
                    else if(s == "*"){
                        st.push((long long)x*y);
                    }
                    else{
                        st.push(x/y);
                    }
                }
            }
        }
        return (st.top());
    }
};