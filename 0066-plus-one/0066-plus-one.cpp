class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k = 1;
        vector<int> ans;
        int carry = 0,sum = 0;
      
        int m = digits.size(),n = 1;
        
        int idx = m - 1;
        while(idx >= 0 and k){
            sum = (carry) + (k % 10) + digits[idx--];
            carry = sum/10;
            ans.push_back(sum % 10);
            k /= 10;
        }
            
        while(idx >= 0){
            int sum = (k % 10) + digits[idx--] + carry;
            carry = sum/10;
            ans.push_back(sum % 10);
            k /= 10;
        }
        
        while(k){
            int sum = (k % 10) + carry;
            carry = sum/10;
            ans.push_back(sum % 10);
            k /= 10;
        }
            
        if(carry){
            ans.push_back(1);
        }
            
        reverse(ans.begin(),ans.end());
    
        return ans;
    }
};