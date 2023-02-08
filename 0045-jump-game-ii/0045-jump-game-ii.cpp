class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if( n <= 1 ){
            return 0 ;
        }
        pair<int,int> path={0,0};
        int jumps = 0 ;
        while( true ){
            int reach = 0 ;
            jumps++;
            for( int i = path.first ; i<= path.second ; i++){
                reach = max (reach, i+nums[i]);
            }
            // cout << path.first << " " << path.second <<endl ;
            path = { path.second + 1 , reach };

            if( reach >= n-1 ){
                return jumps ;
            }
            if ( path.first > path.second ){
                return -1;
            }
        }
        return jumps;
    }
};