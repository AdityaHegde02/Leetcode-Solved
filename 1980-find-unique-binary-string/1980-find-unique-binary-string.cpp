class Solution {
public:
    void generate(string &temp,int i,int n,vector<string> &allStrings){
        if(i >= n){
            allStrings.push_back(temp);
            return;
        }
        
        temp += '0';
        generate(temp,i + 1,n,allStrings);
        temp.pop_back();
        temp += '1';
        generate(temp,i + 1,n,allStrings);
        temp.pop_back();
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> s(nums.begin(),nums.end());
        vector<string> allStrings;
        string temp = "";
        generate(temp,0,n,allStrings);
        for(int i = 0; i < allStrings.size(); i++){
            if(s.count(allStrings[i]) == 0){
                return allStrings[i];
            }
        }
        return "";
    }
};