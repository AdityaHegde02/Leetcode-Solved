class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx and sy == fy){
            return (t != 1);
        }
        int d1 = abs(sx - fx), d2 = abs(sy - fy), mn1;
        if(d1 <= d2){
            mn1 = d1 + abs(max(fy,sy) - min(fy,sy) - d1);
        }
        else{
            mn1 = d2 + abs(max(fx,sx) - min(fx,sx) - d2);
        }
        
        return mn1 <= t;
    }
};