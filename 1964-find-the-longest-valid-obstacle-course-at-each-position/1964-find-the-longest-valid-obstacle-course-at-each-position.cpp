class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> lis;
        
        for(int i = 0; i < obstacles.size(); ++i){
            if(i == 0 || obstacles[i] >= lis.back()){
                lis.push_back(obstacles[i]);
                ans.push_back(lis.size());
            }
            else{
                int index = upper_bound(lis.begin(),lis.end(),obstacles[i]) - lis.begin();
                lis[index] = obstacles[i];
                ans.push_back(index + 1);
            }
        }
        return ans;
    }
};