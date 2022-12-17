#define pi pair<double,int>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<vector<int>> kClosePoints;
        priority_queue<pi,vector<pi>,greater<pi>> maxheap;
        for(int i = 0; i < p.size(); i++){
            int x = p[i][0], y = p[i][1];
            double d = sqrt(x*x + y*y);
            maxheap.push({d,i});
        }
        while(k--){
            auto top = maxheap.top();
            kClosePoints.push_back(p[top.second]);
            maxheap.pop();
        }
        return kClosePoints;
    }
};