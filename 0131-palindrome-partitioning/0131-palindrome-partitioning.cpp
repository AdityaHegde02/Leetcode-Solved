class Solution {
public:
    vector<vector<string>> result;
    
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    
    void partition(string& s, int start, vector<string>& path) {
        if (start >= s.size()) {
            result.push_back(path); return ;
        } 
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                partition(s, i + 1, path);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> path;
        partition(s, 0, path);
        return result;
    }
};