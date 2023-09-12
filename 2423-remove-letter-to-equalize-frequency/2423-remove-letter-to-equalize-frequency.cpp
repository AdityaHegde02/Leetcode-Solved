class Solution {
public:
    bool equalFrequency(string word) {
        int n = word.size();
        unordered_map<char,int> charCount;
        for(auto &i : word){
            charCount[i]++;
        }
        
        unordered_map<char,int> temp;
        for(auto &i : charCount){
            temp = charCount;
            temp[i.first]--;
            if(temp[i.first] == 0){
                temp.erase(i.first);
            }
            unordered_set<int> st;
            for(auto &j : temp){
                st.insert(j.second);
            }
            if(st.size() == 1){
                return true;
            }
        }
        
        return false;
    }
};