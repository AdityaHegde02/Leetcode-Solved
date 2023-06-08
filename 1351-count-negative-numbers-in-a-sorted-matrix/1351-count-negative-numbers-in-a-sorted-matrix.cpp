class Solution {
public:
    int bs(vector<int> &a){
        int n = a.size();
        int low = 0, high = n - 1;
        int idx = n;
        while(low <= high){
            int mid = (low + high)/2;
            if(a[mid] < 0){
                idx = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return idx;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int neg = 0;
        for(int i = 0; i < grid.size(); i++){
            int idx = bs(grid[i]);
            neg += (grid[0].size() - idx);
        }
        
        return neg;
    }
};