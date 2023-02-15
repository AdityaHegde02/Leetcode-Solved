class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = 0,sum = 0;
        string s = to_string(k);
        int m = num.size(),n = s.size();
        
        int idx = m - 1;
        while(idx >= 0 and k){
            sum = (carry) + (k % 10) + num[idx--];
            carry = sum/10;
            ans.push_back(sum % 10);
            k /= 10;
        }
            
        while(idx >= 0){
            int sum = (k % 10) + num[idx--] + carry;
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