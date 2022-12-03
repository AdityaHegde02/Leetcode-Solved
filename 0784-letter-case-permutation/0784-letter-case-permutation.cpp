class Solution {
public:
    unordered_set<string> set;
    
    void generate(int i,int n,string &s){
        if(i == n){
            if((s.back() >= 'a' and s.back() <= 'z') or (s.back() >= 'A' and s.back() <= 'Z') and (set.find(s) == set.end())){
                set.insert(s);
            }
            return ;
        }
        
        if(set.find(s) == set.end())
            set.insert(s);
        
        if(s[i] >= 'A' and s[i] <= 'Z'){
            s[i] = s[i] + 32;
            generate(i + 1,n,s);
            s[i] = s[i] - 32;
            generate(i + 1,n,s);
        }
        
        else if(s[i] >= 'a' and s[i] <= 'z'){
            s[i] = s[i] - 32;
            generate(i + 1,n,s);
            s[i] = s[i] + 32;
            generate(i + 1,n,s);
        }
        
        else{
            generate(i + 1,n,s);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> strings;
        generate(0,n,s);
        for(auto &s : set){
            strings.push_back(s);
        }
        return strings;
    }
};