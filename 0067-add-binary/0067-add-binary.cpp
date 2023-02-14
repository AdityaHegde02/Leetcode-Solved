class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        int carry = 0;
        string ans = "";
        int i = m - 1, j = n - 1;
        while(i >= 0 and j >= 0){
            if(a[i] == '1' and b[j] == '1'){
                if(carry){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
                carry = 1;
            }
            else if(a[i] == '0' and b[j] == '0'){
                if(carry){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
                carry = 0;
            }
            else{
                if(carry){
                    ans += '0';
                    carry = 1;
                }
                else{
                    ans += '1';
                    carry = 0;
                }
            }
            
            i--;
            j--;
        }
        
        while(i >= 0){
            if(a[i] == '1'){
                if(carry){
                    ans += '0';
                    carry = 1;
                }
                else{
                    ans += '1';
                    carry = 0;
                }
            }
            else{
                if(carry){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
                carry = 0;
            }
            i--;
        }
        
        while(j >= 0){
            if(b[j] == '1'){
                if(carry){
                    ans += '0';
                    carry = 1;
                }
                else{
                    ans += '1';
                    carry = 0;
                }
            }
            else{
                if(carry){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
                carry = 0;
            }
            j--;
        }
        
        if(carry){
            ans += '1';
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};