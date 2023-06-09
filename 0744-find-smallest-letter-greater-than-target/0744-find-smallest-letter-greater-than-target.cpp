class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char key) {
        int idx = upper_bound ( a.begin(), a.end(), key) - a.begin() ;
        return (idx < a.size()) ? a[idx] : a[0] ;
    }
};