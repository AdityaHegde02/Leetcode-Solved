class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& add) {
        int n = a.size() + 1;
        vector<vector<int>> ans;
        a.push_back(add);
        sort( a.begin() , a.end() );
        for( int i= 0; i < n -1 ; i++){
            if( a[i][1] >= a[ i+1 ][0]){
                a[ i+1 ][0] = min( a[i][0] , a[i+1][0]);
                a[ i+1 ][1] = max( a[i][1] , a[i+1][1]);
            }
            else{
                ans.push_back( a[i] );
            }
        }
        ans.push_back(a[n-1]);
        return ans;
    }
};