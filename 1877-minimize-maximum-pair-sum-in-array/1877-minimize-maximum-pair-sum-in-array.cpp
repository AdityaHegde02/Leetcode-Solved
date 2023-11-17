const static auto fast=[]{
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}();

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // we can either sort nums and use two pointers
        // TC = O(NLogN)
        // second solution makes the frequency array
        // TC = O(N)
        int n = nums.size();
        int maxi = 0;
        int mini = 1e5+1;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        vector<int>freq(maxi - mini + 1, 0);
        for(int i = 0; i < n; i++){
            freq[nums[i] - mini] ++;
        }
        int i = 0;
        int j = maxi - mini;
        int ans = 0;
        while(i <= j){
            if(i == j){
                if(freq[i] < 2){
                    break;
                }
            }
            while(freq[i] == 0 && i < maxi - mini ){
                i++;
            }
            while(freq[j] == 0 && j > 0){
                j--;
            }
            ans = max(ans, i + j + 2 * mini);
            freq[i]--;
            freq[j]--;
        }
        return ans;
    }
};