class Solution {
public:
    bool isPal(string s){
        string t = s;
        reverse(s.begin(),s.end());
        return (s==t)?1:0;
    }
    
    string firstPalindrome(vector<string>& words) {
        for(int i = 0 ; i < words.size() ; i++){
            if(isPal(words[i])){
                return words[i];
            }
        }
        return "";
    }
};