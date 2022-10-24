class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>> ans;
        set<string> fooditems;
        for(auto &i : orders){
            fooditems.insert(i[2]);
        }
        
        vector<string> heading = {"Table"};
        for(auto &i : fooditems){
            heading.push_back(i);
        }
        
        ans.push_back(heading);
        
        map<int,map<string,int>> tableItemFreq;
        
        for(auto &i : orders){
            tableItemFreq[stoi(i[1])][i[2]]++;
        }
        
        for(auto &i : tableItemFreq){
            vector<string> temp;
            temp.push_back(to_string(i.first));
            for(auto &j : fooditems){
                if(tableItemFreq[i.first].count(j)){
                    temp.push_back(to_string(tableItemFreq[i.first][j]));
                }
                else{
                    temp.push_back(to_string(0));
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};