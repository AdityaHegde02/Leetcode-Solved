class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l = left.size(), r = right.size();
        int leftlast = 0, rightfirst = n;
        sort(left.begin(),left.end());
        sort(right.begin(),right.end());
        if(l != 0){
            leftlast = left[l - 1];
        }
        if(r != 0){
            rightfirst = right[0];
        }
        return max(leftlast,n - rightfirst);
    }
};