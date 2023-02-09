class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        int n = ideas.size();
        
        unordered_map<char,vector<string>> blocks;
        unordered_set<string> words(ideas.begin(),ideas.end());
        
        for(auto &i : ideas){
            blocks[i[0]].push_back(i.substr(1,i.size() - 1));
        }
        
        for(auto &i : blocks){                  // first block
            for(auto &j : blocks){              // second block
                int m = i.second.size(), n = j.second.size();
                int x = 0, y = 0;
                for(int k = 0; k < m; k++){     // iterating over first block
                    string search = j.first + i.second[k];
                    if(words.find(search) != words.end()){
                        x++;
                        y++;
                    }
                }
                ans += (m - x)*(n - y);
            }
        }
        
        return ans;
    }
};