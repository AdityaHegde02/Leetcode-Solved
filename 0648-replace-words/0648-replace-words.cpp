class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        stringstream s(sentence);
        
        string currWord;
        
        unordered_map<string,int> mp;
        
        for(auto &i : dictionary){
            mp[i]++;
        }
        
        while(s >> currWord){
            int n = currWord.size();
            int i = 0;
            string pre ;
            bool f = 0;
            while(i < n){
                pre += currWord[i];
                if(mp[pre]){
                    f = 1;
                    ans += pre + " ";
                    break;
                }
                i++;
            }
            if(!f){
                ans += currWord + " ";
            }
        }
        
        ans.pop_back();
        
        return ans;
    }
};