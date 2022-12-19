class Solution {
public:
    vector<bool> camelMatch(vector<string>& q, string p) {
        vector<bool> ans;
        int m = q.size(),n = p.size();
        for(int i = 0; i < m; i++){
            string word = q[i];
            int x = 0, y = 0;
            bool t = true;
            while(x < word.size() and y < n){
                if(word[x] == p[y]){
                    x++;y++;
                }
                else if(word[x] < 91){
                    t = false;
                    break;
                }
                else{
                    x++;
                }
            }
            if(t == false){
                ans.push_back(t);
                continue;
            }
            while(x < word.size()){
                if(word[x] < 91){
                    t = false;
                    break;
                }
                else{
                    x++;
                }
            }
            if(y < n){
                t = false;
            }
            ans.push_back(t);
        }
        return ans;
    }
};