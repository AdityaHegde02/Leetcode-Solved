class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto &i : emails){
            string s = i;
            string t = "";
            int at = -1;
            for(auto j = 0; j < s.size(); j++){
                if(s[j] == '.'){
                    continue;
                }
                if(s[j] == '+'){
                    while(s[j] != '@'){
                        j++;
                    }
                    at = j;
                    break;
                }
                else if(s[j] == '@'){
                    at = j;
                    break;
                }
                else{
                    t += s[j];
                }
            }
            for(int j = at; j < s.size(); j++){
                t += s[j];
            }
            
            st.insert(t);
        }
        return st.size();
    }
};