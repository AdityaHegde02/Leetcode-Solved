class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";
        int n = s.size();
        
        map<char,vector<int>> indices;
        
        for(int i = 0; i < n; i++){
            indices[s[i]].push_back(i);
        }
        
        while(indices.size()){
            // picking smallest possible
            for(auto &i : indices){
                int start = i.second[0];
                // take min of last indices
                int mn = n;
                for(auto &j : indices){
                    if(j.first != i.first){
                        mn = min(mn,j.second[j.second.size() - 1]);
                    }
                }
                
                if(start < mn ){
                    ans += i.first;
                    indices.erase(i.first);
                    for(auto &k : indices){
                        int del = 0;
                        for(int l = 0; l < k.second.size(); l++){
                            if(k.second[l] > start){
                                del = l - 1;
                                break;
                            }
                        }
                        
                        for(int l = 0; l <= del; l++){
                               auto it = find(k.second.begin(), k.second.end(), k.second[0]);
    k.second.erase(it);
                        }
                    }
                    break;
                }
            }
        }
        
        return ans;
    }
};