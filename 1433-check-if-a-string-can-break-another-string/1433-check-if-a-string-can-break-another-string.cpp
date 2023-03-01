class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        bool f = 1;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] < s2[i]){
                f = 0;
                break;
            }
        }
        
        if(f){
            return true;
        }
        
        f = 1;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] > s2[i]){
                f = 0;
                break;
            }
        }
        
        return f;
    }
};