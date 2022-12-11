class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int half=0,start=0;
        for(int i=0;i<S.length();++i)   {
            if(S[i]=='(')
                ++half;
            else
                --half;
            if(0==half) {
                res.append(S.substr(start+1,i-start-1));
                start=i+1;
            }
        }
        return res;
    }
};