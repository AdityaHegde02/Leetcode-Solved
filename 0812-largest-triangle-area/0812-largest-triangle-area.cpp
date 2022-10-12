class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int no_points = points.size();
        double mx = -1;
        for(int i = 0 ; i < no_points - 2 ; i++){
            for(int j = i + 1 ; j < no_points - 1 ; j++){
                for(int k = j + 1 ; k < no_points ; k++){
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    double p = x1*(y2-y3);
                    double q = x2*(y3-y1);
                    double r = x3*(y1-y2);
                    double a = (0.5)*abs(double(p+q+r));
                    mx = max(mx,a);
                }
            }
        }
        return mx;
    }
};