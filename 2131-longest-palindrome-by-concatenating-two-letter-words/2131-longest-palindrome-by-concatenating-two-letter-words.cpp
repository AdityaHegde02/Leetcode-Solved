class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        
        for(auto &i : words){
            mp[i]++;
        }
        
        int mx = 0;
        bool single = 0;
           
        for(int i = 0; i < words.size() ; i++){
            string a = words[i];
            string b = a;
            reverse(b.begin(),b.end());
            if(a[0] == a[1]){
                if(mp[a] % 2){
                    if(single){
                        mx += 2*(mp[a] - 1);
                        mp[a] = 1;
                    }
                    else{
                        mx += 2*(mp[a]);
                        mp[a] = 0;
                        single = 1;
                    }
                }
                else{
                    mx += 2*(mp[a]);
                    mp[a] = 0;
                }
            }
            else if(mp[b]){
                mx += 4*min(mp[a],mp[b]);
                mp[a] = 0;
                mp[b] = 0;
            }
        }
        
        return mx;
    }
};