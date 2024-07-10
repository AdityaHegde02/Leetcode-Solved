class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        for(auto &i : logs){
            if(i[1] == '.'){
                step = max(0,step - 1);
            }
            else if(i[0] != '.'){
                step++;
            }
        }
        return step;
    }
};