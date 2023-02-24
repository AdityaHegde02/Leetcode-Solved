class Solution {
public:
  vector <int> merge(vector<int>& nums1,int m,vector<int>& nums2, int n) {
      map<int,int> mp;
      for(int i=0;i<m;i++){
          mp[nums1[i]]++;
      }
    
      for(int i=0;i<n;i++){
          mp[nums2[i]]++;
      }

      int i=0;
      map<int,int>::iterator it=mp.begin();
      while(it!=mp.end()){
          if((it->second)>1){
              nums1[i]=it->first;
              i++;
              (it->second)--;
          }
          else{
              nums1[i]=it->first;
              i++;
              it->second--;
              it++;
          }
      }
      return nums1;
  }
};