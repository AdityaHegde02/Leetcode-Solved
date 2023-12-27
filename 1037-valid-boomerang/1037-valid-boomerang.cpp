class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if(points[0] == points[1] or points[0] == points[2] or points[1] == points[2]){
            return 0;
        }
        
        double s1 = (points[1][1] - points[0][1])*(points[2][0] - points[1][0]);
        double s2 = (points[2][1] - points[1][1])*(points[1][0] - points[0][0]);
        return (s1 != s2);
    }
};