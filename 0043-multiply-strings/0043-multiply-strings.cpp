class Solution {
public:
    string multiply(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> ans(n + m,0);
        if(a == "0" or b == "0"){
            return "0";
        }
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                int pro = ((a[i]-'0')*(b[j]-'0'));
                int ind = i + j + 1;
                int carry = 0;
                while(ind >= 0 and (ans[ind] + pro + carry) != ans[ind]){
                    int prevCarry = carry;
                    carry = (ans[ind] + pro + carry) / 10;
                    ans[ind] = (ans[ind] + pro + prevCarry) % 10;
                    pro = 0;
                    ind--;
                }
            }
        }
        string res = "";
        int i = 0;
        while(i < ans.size() and ans[i] == 0){
            i++;
        }
        while(i < ans.size()){
            res += to_string(ans[i]);
            i++;
        }
        return res;
    }
};