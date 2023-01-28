class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        int mxPencils = (total)/cost1;
        int mxPens = (total)/cost2;
        long long ans = 0;
        for(int pencils = 0; pencils <= mxPencils; pencils++){
            long long cost = (long long)(pencils)*(cost1);
            long long remain = total - cost;
            long long pens = (remain)/cost2;
            ans += pens + 1;
        }
        return ans;
    }
};