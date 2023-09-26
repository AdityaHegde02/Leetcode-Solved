class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        int n = s.size();
        
        map<char,vector<int>> indices;
        for(int i = 0; i < n; i++){
            indices[s[i]].push_back(i);
        }
        
        while(indices.size()){
            for(auto &i : indices){         // picking smallest possible
                int start = i.second[0];
                int mn = n;                 // take min of last indices
                for(auto &j : indices){
                    if(j.first != i.first){
                        mn = min(mn,j.second[j.second.size() - 1]);
                    }
                }
                
                if(start < mn ){            // got possible
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
                               k.second.erase(find(k.second.begin(), k.second.end(), k.second[0]));
                        }
                    }
                    break;
                }
            }
        }
        
        return ans;
    }
};