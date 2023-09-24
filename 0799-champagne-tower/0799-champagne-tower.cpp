class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int level = 0;
        double ans = 0, p = poured;
        if(query_row == 0){
            return (poured >= 1);
        }
        if(poured == 0){
            return 0;
        }
        vector<double> prev = {p}, curr;
        while(level < 100){
            vector<double> curr(prev.size() + 1,0);
            //  cout << level << endl;
            for(int i = 0; i < prev.size(); i++){
                if(prev[i] > 1){
                    curr[i] += (double)(prev[i] - 1)/2.0;
                    curr[i + 1] += (double)(prev[i] - 1)/2.0;
                    prev[i] = 1;
                }
                // cout << curr[i] << " ";
            }
            // cout << endl;
            level++;
            prev = curr;
            
            if(level == query_row){
                if(curr[query_glass] > 1){
                    ans = 1;
                }
                else{
                    ans = curr[query_glass];
                }
                break;
            }
        }
        return ans;
    }
};