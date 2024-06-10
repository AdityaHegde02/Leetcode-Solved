class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int num=0;
        vector<int> expected=heights;
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i]){
                num++;
            } 
        }
        return num;
    }
};