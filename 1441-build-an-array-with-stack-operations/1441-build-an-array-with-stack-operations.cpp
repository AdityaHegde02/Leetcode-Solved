class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int len = target.size();
        int i = 1;
        int j = 0;
        stack<int> st;
        while(i <= n and j < len){
            if(i == target[j]){
                st.push(i);
                ans.push_back("Push");
                j++;
                if(j == len){
                    return ans;
                }
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            i++;
        }
        return ans;
    }
};