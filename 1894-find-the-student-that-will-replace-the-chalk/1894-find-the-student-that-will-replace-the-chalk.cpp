class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum = 0;
        for(int &i : chalk){
            sum += i;
        }
        
        if(sum > k){
            long long int curr = 0;
            for(int i = 0; i < chalk.size(); i++){
                if(k < chalk[i]){
                    return i;
                }
                k -= chalk[i];
                curr += chalk[i];
            }
        }
        
        long long x = k/sum;
        long long y = x*sum;
        k -= y;
        long long int curr = 0;
        for(int i = 0; i < chalk.size(); i++){
            if(k < chalk[i]){
                return i;
            }
            k -= chalk[i];
            curr += chalk[i];
        }
        return 0;
    }
};