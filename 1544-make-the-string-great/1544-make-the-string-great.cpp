class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        while(true){
            int i = 0;
            bool f = 0;
            while(i < n - 1){
                if(abs(s[i]-s[i+1]) != 32){
                    i++;
                }
                else{
                    f = 1;
                    s.erase(s.begin()+i);
                    s.erase(s.begin()+i);
                    i++;
                }
            }
            if(f == 0){
                break;
            }
        }
        return s;
    }
};