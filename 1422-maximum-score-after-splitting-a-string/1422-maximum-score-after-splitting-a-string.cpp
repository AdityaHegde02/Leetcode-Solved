class Solution {
public:
    int maxScore(string s) {
        int mx = 0, z = 0, o = 0;
        for(auto &i : s){
            o += (i == '1');
        }
        
        int cnt = 0;
        for(auto &i : s){
            int x = (i == '0')? z++ : o--;
            mx = max(mx,z + o);
            cnt++;
            if(cnt == s.size() - 1){
                break;
            }
        }
        return mx;
    }
};