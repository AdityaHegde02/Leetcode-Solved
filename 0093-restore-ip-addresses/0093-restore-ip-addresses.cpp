class Solution {
public:
    vector<string> ans;
    
    bool isValid(string s){
        if(s.size() == 0 or s.size() > 3){
            return false;
        }
        if(s.size() > 1 and s[0] == '0'){
            return false;
        }
        int num = stoi(s);
        if(num <= 255 and num >= 0){
            return true;
        }
        return false;
    }
    
    void solve(int i,int dots,string temp,string &s){
        if(dots > 3){
            return ;
        }
        if(dots == 3){
            if(isValid(s.substr(i))){
                ans.push_back(temp + s.substr(i));
            }
            return ;
        }
        
        for(int j = i; j < s.size(); j++){
            if(isValid(s.substr(i,j - i + 1))){
                temp.push_back(s[j]);
                temp.push_back('.');
                solve(j + 1, dots + 1,temp, s);
                temp.pop_back();
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        if(n < 4 or n > 12){
            return {};
        }
        solve(0,0,"",s);
        return ans;
    }
};