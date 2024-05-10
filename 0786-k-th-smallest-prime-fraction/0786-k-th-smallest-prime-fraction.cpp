class Solution {
public:
    #define t pair<double,pair<int,int>> 
    
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<t,vector<t>,greater<t>> q;
        double x = (arr[0]/(double)arr[n - 1]);
        q.push({x,{0,n-1}});
        vector<vector<int>> vis(n,vector<int> (n,0));
        vis[0][n - 1] = 1;
        while(k){
            auto top = q.top();
            q.pop();
            double val = top.first;
            int x = top.second.first, y = top.second.second;
            
            if(k == 1){
                return {arr[x],arr[y]};
            }
        
            if( x < n and y >= 0 and x + 1 < y and !vis[x + 1][y]){
                double a = (arr[x + 1]/(double)arr[y]);
                vis[x + 1][y] = 1;
                q.push({a,{x + 1,y}});
            }
            if( x < n and y >= 0 and x < y - 1 and !vis[x][y - 1]){
                double a = (arr[x]/(double)arr[y - 1]);
                vis[x][y - 1] = 1;
                q.push({a,{x,y - 1}});
            }
            k--;
        }
        return {0,0};
    }
};