class Solution {
public:
    int punishmentNumber(int n) {
        int ans=0;
        
        for(int i=1;i<=n;i++){
            int num=i*i;
            string s=to_string(num);
            
            if(helper(s, 0, i)) ans += num;
        }
        
        return ans;
    }
    
    bool helper(string& s, int idx, int sum){
        if(idx==s.size()) return (sum == 0);
        if(sum<0) return false;
        
        int left=0;
        
        for(int i=idx;i<s.size();i++){
            left = (left*10) + (s[i] - '0');
            
            bool found=helper(s, i+1, sum - left);
            
            if(found) return true;
        }
        
        return false;
    }
};