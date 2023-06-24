class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        vector<pair<int,int>> idx;
        for(int i = 0; i < nums2.size(); i++){
            idx.push_back({nums2[i],i});
        }
        sort(idx.begin(),idx.end(),cmp);
        sort(nums2.begin(),nums2.end());
        vector<int> ans(nums2.size());
        int l = 0, r = nums1.size() - 1;
        for(int i = nums2.size() - 1; i >= 0; i--){
            if(nums2[i] >= nums1[r]){
                ans[idx[i].second] = nums1[l];
                l++;
            }
            else{
                ans[idx[i].second] = nums1[r];
                r--;
            }
        }
        
        return ans;
    }
};