class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        string reversed;
        int start = 0;
        while(start<len){
            string temp;
            while(start < len and s[start] != ' '){
                temp += s[start++];
            }
            start++;
            reverse(temp.begin(),temp.end());
            if(start<len)
                reversed += (temp) + ' ';
            else
                reversed += (temp);
        }
        return reversed;
    }
};