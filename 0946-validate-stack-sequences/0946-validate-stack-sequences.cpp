class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        vector<int> vis(n + 1,0);
        int j = 0;
        
        for(int i = 0; i < n; i++){
            int val = popped[i];
            if(vis[val] == 1){
                if(!st.empty() and st.top() == val){
                    st.pop();
                    continue;
                }
                else{
                    return false;
                }
            }
            for(int k = j; k < n; k++){
                vis[pushed[k]] = 1;
                if(pushed[k] == val){
                    j = k + 1;
                    break;
                }
                else{
                    st.push(pushed[k]);
                }
            }
        }
        
        return true;
    }
};