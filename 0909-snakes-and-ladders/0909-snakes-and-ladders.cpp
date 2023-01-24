class Solution {
public:
    vector<int> calc(int row,int next_step)
    {
        int x=(next_step-1)/row;
        int y=(next_step-1)%row;
        if(x%2==1)y=row-1-y;
        x=row-1-x;
        return {x,y};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int r=board.size();
        queue<int> q;
        q.push(1);
        int step=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int t=q.front();
                q.pop();
                if(t==r*r)return step;
                for(int i=1;i<=6;i++)
                {
                    int next_step=t+i;
                    if(next_step>r*r)break;
                    auto v=calc(r,next_step); 
                    int row=v[0],col=v[1];
                    if(board[row][col]!=-1)
                    {
                        next_step=board[row][col];
                    }
                    if(board[row][col]!=r*r+1)
                    {
                        q.push(next_step);
                        board[row][col]=r*r+1;
                    }
                }
            }
            step++;
        }
        return -1;
    }
};