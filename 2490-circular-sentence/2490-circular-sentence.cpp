class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.size();
        if(s[0] != s[n - 1]){
            return false;
        }
        stringstream ss(s);
        string prev = "";
        string temp = "";
        ss >> prev;
        while(ss >> temp){
            if(prev[prev.size() - 1] != temp[0]){
                return false;
            }
            prev = temp;
        }
        return true;
    }
};