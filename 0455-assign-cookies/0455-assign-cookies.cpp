class Solution {
public:
    int findContentChildren(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int j=0,count=0;
        
        for(int i=0;i<b.size();i++){
            if(j<a.size() and b[i]>=a[j]){ 
                count++;
                j++;
            }
        }
        return count;
    }
};