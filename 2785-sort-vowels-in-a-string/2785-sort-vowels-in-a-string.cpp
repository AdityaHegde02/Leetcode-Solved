class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(auto &i : s){
            if(i == 'a' or i == 'e' or i == 'o' or i == 'i' or i == 'u' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i=='U'){
                vowels.push_back(i);
            }
        }
        
        sort(vowels.begin(),vowels.end());
        int j = 0;
        for(auto &i : s){
            if(i == 'a' or i == 'e' or i == 'o' or i == 'i' or i == 'u' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i=='U'){
                i = vowels[j++];
            }
        }
        
        return s;
    }
};