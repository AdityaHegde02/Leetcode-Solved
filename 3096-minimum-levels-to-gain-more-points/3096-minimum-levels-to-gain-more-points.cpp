class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int n = p.size(),a = 0, ones = 0;
        int sum = accumulate(p.begin(),p.end(),0);
        for(int i = 0; i < n - 1; i++){
            a += (p[i] == 1) ? 1 : -1;
            ones += p[i];
            int b = (sum - ones) - (n - i - 1 - (sum - ones));
            if(a > b){
                return i + 1;
            }
        }
        return -1;
    }
};