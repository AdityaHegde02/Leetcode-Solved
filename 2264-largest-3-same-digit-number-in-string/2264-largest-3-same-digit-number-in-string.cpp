class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        int number = -1;
        for(int i=1 ; i<n-1 ;i++){
            if(num[i]==num[i+1] and num[i]==num[i-1]){
                number = max(number,num[i]-'0');
                if(number == num[i]-'0' ){
                    ans.clear();
                    for(int j=0;j<3;j++){
                        ans += (num[i]);
                    }
                }
            }
        }
        return ans;
    }
};