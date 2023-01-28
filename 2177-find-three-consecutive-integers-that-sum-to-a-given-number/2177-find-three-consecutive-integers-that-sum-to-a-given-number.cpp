class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num == 0){
            return {-1,0,1};
        }
        long long l = 0, r =(num/3);
        while(l <= r){
            long long mid = l + (r - l)/2;
            long long sum = 3*mid + 3;
            if(sum ==  num){
                return {mid,mid+1,mid+2};
            }
            else if(sum > num){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return {};
    }
};