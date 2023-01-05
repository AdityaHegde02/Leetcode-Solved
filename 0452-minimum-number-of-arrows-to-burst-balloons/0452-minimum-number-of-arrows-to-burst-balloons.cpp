class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int arrow = points[0][1], ans = 1;
        for(int i = 1; i < points.size(); i++){
            if(points[i][0] > arrow){
                ans++;
                arrow = points[i][1];
            }
            else{
                arrow = min(arrow,points[i][1]);
            }
        }
        return ans;
    }
};