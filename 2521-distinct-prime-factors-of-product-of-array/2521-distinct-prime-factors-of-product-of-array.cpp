class Solution {
public:
    vector<int> primes;
    
    void sieve(vector<int> &arr){
        for(int i = 2; i*i <= 1000; i++){
            if(arr[i] == 1){
                primes.push_back(i);
                for(int j = i*i; j <= 1000; j += i){
                    arr[j] = 0;
                }
            }
        }
    }
    
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> set;
        vector<int> arr(1001,1);
        int n = nums.size();
        sieve(arr);
        for(int &i : nums){
            for(int &j : primes){
                while(i % j == 0){
                    set.insert(j);
                    i /= j;
                }
            }
            if(i > 1){
                set.insert(i);
            }
        }
        return set.size();
    }
};