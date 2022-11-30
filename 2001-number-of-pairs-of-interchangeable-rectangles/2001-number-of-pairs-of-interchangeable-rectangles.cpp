class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        unordered_map<double,int> ratios;
        
        for(auto &i : rectangles){
            double r = (double)(i[0])/i[1];
            ratios[r]++;
        }
        
        long long int ans = 0;
        for(auto &i : ratios){
            long long sec = i.second;
            ans += (sec*(sec-1))/2;
        }
        
        return ans;
    }
};