class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long int sum = 0;
        for(int &i : arr){
            sum += i;
        }
        
        if(sum % 3 != 0){
            return false;
        }
        
        long long int x = sum/3,curr = 0;
    
        int t = 0;
        
        for(int i = 0; i < arr.size(); i++){
            curr += arr[i];
            if(curr == x){
                t++;
                curr = 0;
            }
        }
        
        return (t >= 3);
    }
};