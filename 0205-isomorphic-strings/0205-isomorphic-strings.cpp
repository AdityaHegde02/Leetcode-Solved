class Solution {
public:
    bool isIsomorphic(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        if(m != n){
            return false;
        }
        
        unordered_map<char,char> mapped,mappedrev;
        
        for(int i = 0; i < m; i++){
            cout << str1[i] << " " << endl; 
            if(mappedrev.find(str2[i]) != mappedrev.end()){
                if(mappedrev[str2[i]] != str1[i]){
                    return false;
                }
            }
            else if(mapped.find(str1[i]) != mapped.end()){
                if(mapped[str1[i]] != str2[i]){
                    return false;
                }
            }
            else{
                mapped[str1[i]] = str2[i];
                mappedrev[str2[i]] = str1[i];
            }
        }
        
        return true;
    }
};