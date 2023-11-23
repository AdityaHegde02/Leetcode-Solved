class Solution {
public:
    bool checkAri(vector<int>& nums,int l,int r) {
        vector<int> a;
        for(int i=l;i<=r;i++){
            a.push_back(nums[i]);
        }
        sort(a.begin(),a.end());
        int pd=a[1]-a[0];
        bool check=true;
        for(int i=1;i<r-l;i++){
            if(a[i+1]-a[i]!=pd){
                check=false;
                break;
            }
        }
        return check;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size());
        for(int i=0;i<l.size();i++){
            int l1=l[i];
            int r1=r[i];
            ans[i]=checkAri(nums,l1,r1);
        }
        return ans;
    }
};