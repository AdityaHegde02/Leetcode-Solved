class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        
        for(auto &i : words){
            mp[i]++;
        }
        
        int mx = 0;
        bool f = 0;
           
        for(int i = 0; i < words.size() ; i++){
            string b = words[i];
            string a = b;
            reverse(b.begin(),b.end());
            if(a[0] == a[1] and mp[a] % 2 == 0){
                mx += 2*mp[a];
                mp[a] = 0;
            }
            else if(a[0] == a[1] and mp[a] % 2 and !f){
                f = 1;
                mx += 2*mp[a];
                mp[a] = 0;
            }
            else if(a[0] == a[1] and mp[a] % 2){
                mx += 2*(mp[a]-1);
                mp[a] = 0;
            }
            else if(a[0] != a[1] and mp[b]){
                mx += 4*(min(mp[a],mp[b]));
                mp[a] = 0;
                mp[b] = 0;
            }
        }
        
        return mx;
    }
};