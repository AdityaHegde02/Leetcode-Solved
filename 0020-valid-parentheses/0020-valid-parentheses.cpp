class Solution
{
public:
    bool isValid(string s)
    {
        if(s.length()==1 or s[0]==')' or s[0]==']' or s[0]=='}'){
            return false;
        }
        stack<char> st;
        map<char,char> mp;
        mp.insert({'(',')'});
        mp.insert({'{','}'});
        mp.insert({'[',']'});
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else if(st.empty() and (s[i]=='}' or s[i]==')' or s[i]==']')){
                return false;
            }
            else{
                for(auto a:mp){
                    if(s[i]==a.second){
                        if(a.first==st.top()){
                            st.pop();
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};