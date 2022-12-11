class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        // next greater element using stack
        string ans = "";
        stack<char> st;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() and k and st.top() > num[i]){
                st.pop();
                k--;
            }
            
            st.push(num[i]);
        }
        
        while(!st.empty() and k--){
            st.pop();
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        while(ans.back() == '0'){
            ans.pop_back();
        }
        
        reverse(ans.begin(),ans.end());
        
        return (ans == "")?("0"):ans;
    }
};