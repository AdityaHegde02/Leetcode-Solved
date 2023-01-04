class Solution {
public:
    int numberOfSubstrings(string s) {
        long long int n = s.size(), ans = 0;
        vector<int> count(3,0);
        int i = 0, j = 0;
        while(i < n - 2){
            while(j < n and (count[0] < 1 or count[1] < 1 or count[2] < 1)){
                count[s[j++] - 'a']++;
            }
            if(count[0] >= 1 and count[1] >= 1 and count[2] >= 1 )
                ans += n - j + 1;
            count[s[i] - 'a']--;
            i++;
        }
        return ans;
    }
};