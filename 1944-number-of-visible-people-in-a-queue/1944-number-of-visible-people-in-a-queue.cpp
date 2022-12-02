class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        st.push(heights[n - 1]);
        vector<int> ans;
        ans.push_back(0);
        
        int i = n - 2;
        while(i >= 0 and !st.empty()){
            int l = 0;
            while(!st.empty() and st.top() < heights[i]){
                st.pop();
                l++;
            }
            
            if(st.empty()){
                ans.push_back(l);
            }
            else{
                ans.push_back(l + 1);
            }
            
            st.push(heights[i--]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};