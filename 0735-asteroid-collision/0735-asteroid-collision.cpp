class Solution {
public:
    vector<int> asteroidCollision(vector<int>& s) {
        vector<int> ans;
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s[i] < 0){                   // left 
                    if(st.top() < 0){
                        st.push(s[i]);
                    }
                    else{
                        bool broke = 0;
                        while(!st.empty() and st.top() > 0){
                            if(abs(st.top()) == abs(s[i])){
                                broke = 1;
                                st.pop();
                                break;
                            }
                            else if(abs(st.top()) > abs(s[i])){
                                broke = 1;
                                break;
                            }
                            else{
                                st.pop();
                            }
                        }
                        if(!broke){
                            st.push(s[i]);
                        }
                    }
                }
                else{                           // right
                    st.push(s[i]);
                }
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};