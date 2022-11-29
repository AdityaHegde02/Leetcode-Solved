class Solution {
public:
    void extract(string &dom, int &j){
        while(j < dom.size() and dom[j] != '.'){
            j++;
        }
        return ;
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        int n = cpdomains.size();
        vector<string> ans;
        unordered_map<string,int> mp;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < cpdomains[i].size(); j++){
                int num = 0;
                while(cpdomains[i][j] >= '0' and cpdomains[i][j] <= '9'){
                    num = num*10 + (cpdomains[i][j] - '0');
                    j++;
                }
                j++;
                
                string adomain = cpdomains[i].substr(j);
                mp[adomain] += num;
                extract(cpdomains[i],j);
                j++;
            
                string bdomain = cpdomains[i].substr(j);
                mp[bdomain] += num;
                extract(cpdomains[i],j);
                j++;
                
                if(j < cpdomains[i].size()){
                    string cdomain = cpdomains[i].substr(j);
                    mp[cdomain] += num;
                    j = cpdomains[i].size();
                }
            }
        }
        
        for(auto &pairs : mp){
            string p = to_string(pairs.second) + " " + pairs.first;
            ans.push_back(p);
        }
        
        return ans;
    }
};