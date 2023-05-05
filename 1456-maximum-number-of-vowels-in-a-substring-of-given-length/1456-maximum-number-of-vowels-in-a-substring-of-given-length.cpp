class Solution {
public:
    int check(vector<int> &count){
        return (count[0]) + (count[4]) + (count[8]) + (count[14]) + (count[20]);
    }
    
    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> count(26,0);
        for(int i = 0; i < k; i++){
            count[s[i] - 'a']++;
        }
        
        int curr = check(count);
        
        for(int i = k; i < n; i++){
            count[s[i] - 'a']++;
            count[s[i - k] - 'a']--;
            curr = max(curr,check(count));
        }
        
        curr = max(curr,check(count));
        
        return curr;
    }
};