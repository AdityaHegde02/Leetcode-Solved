class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> diff;
        int i = 0;
        while(i + 1 < n){
            if(heights[i] < heights[i + 1]){
                int d = (heights[i + 1] - heights[i]);
                diff.push(d);
                if(bricks - d < 0){
                    bricks -= d;
                    // cout << i << " " << endl;
                    auto top = diff.top();
                    diff.pop();
                    if(ladders){
                        ladders--;
                        bricks += (top);
                    }
                    else{
                        return i;
                    }
                }
                else{
                    bricks -= d;
                }
            }
            i++;
        }
        return i;
    }
};