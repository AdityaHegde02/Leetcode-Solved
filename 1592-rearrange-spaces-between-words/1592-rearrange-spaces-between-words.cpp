class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        vector<string> w;
        string temp = "";
        for(auto &i : text){
            if(i != ' '){
                temp += i;
            }
            else{
                spaces++;
                if(temp != ""){
                    w.push_back(temp);
                }
                temp = "";
            }
        }
        
        if(temp != ""){
            w.push_back(temp);
        }
        
        int gaps = (w.size() - 1);
        if(gaps == 0){
            string a = w[0];
            a += string(spaces,' ');
            return a;
        }
        
        int fill = (spaces/gaps);
        int left = spaces - (gaps*fill);
        string ans;
        
        for(int j = 0; j < w.size(); j++){
            ans += w[j];
            if(j != w.size() - 1)
                ans += string(fill ,' ');
        }
        
        ans += string(left,' ');
        
        return ans;
    }
};