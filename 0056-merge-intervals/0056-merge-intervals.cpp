class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        int n = a.size();
        
        vector<vector<int>> ans;
        
        sort(a.begin() , a.end());
        
        for( int i = 0 ; i < n - 1 ;i++ ){
            
            if(a[i][1] >= a[i+1][0] ){
                a[i + 1][0] = min ( a[i][0], a[i+1][0] );
                a[ i + 1 ] [1] = max( a[i][1], a[i+1][1]);
            }
            
            else{
                ans.push_back(a[i]);
            }
        }
        ans.push_back( a[n-1] );
        return ans;
    }
};