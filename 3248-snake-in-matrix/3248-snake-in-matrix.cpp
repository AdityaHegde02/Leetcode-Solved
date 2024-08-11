class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int curr = 0;
        for(auto &i : commands){
            if(i == "UP"){
                curr -= n;
            }
            else if(i == "DOWN"){
                curr += n;
            }
            else if(i == "LEFT"){
                curr--;
            }
            else{
                curr++;
            }
        }
        return curr;
    }
};