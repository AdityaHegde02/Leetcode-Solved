class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n=isWater[0].size();
		// 4 Directions
        vector <int> dirs={0,-1,0,1,0};
		// Queue to store cell's row and column information
        queue <pair<int,int>> q;
		// Ans
        vector <vector <int>> ans(m,vector <int>(n,0));
		
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
			// push all water cell in queue
                if(isWater[i][j]==1)
                    q.push({i,j});
            }
        }
		// level
        int l=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                auto p=q.front();
                q.pop();
                ans[p.first][p.second]=l;
                for(int k=1;k<5;k++)
                {
                    int i=p.first+dirs[k-1];
                    int j=p.second+dirs[k];
                    if(i>=0&&j>=0&&i<m&&j<n&&isWater[i][j]==0)
                    {
                        q.push({i,j});
                        isWater[i][j]=1;
                    }
                }
            }
            l++;
        }
        return ans;
    }
};