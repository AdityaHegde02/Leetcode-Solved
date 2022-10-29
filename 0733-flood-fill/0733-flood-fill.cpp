class Solution {
public:
    bool isValid(int x,int y,int m,int n,int currcolor,vector<vector<int>>& image){
        if(x >=m or x < 0 or y >= n or y < 0 or image[x][y] != currcolor){
            return false;
        }
        return true;
    }
    
    void solve(int x,int y,int m,int n,int currcolor,int color,vector<vector<int>>& image){
        if(isValid(x,y,m,n,currcolor,image)){
            image[x][y] = -1;
            solve(x+1,y,m,n,currcolor,color,image);
            solve(x-1,y,m,n,currcolor,color,image);
            solve(x,y+1,m,n,currcolor,color,image);
            solve(x,y-1,m,n,currcolor,color,image);
            image[x][y] = color;
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        
        solve(sr,sc,m,n,image[sr][sc],color,image);
        
        return image;
    }
};