class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int z=n-1,y=n-2,x=0,sum=0;
        while(x<=y){
            sum+=piles[y];
            x++;
            y-=2;
            z-=2;
        }
        return sum;
    }
};