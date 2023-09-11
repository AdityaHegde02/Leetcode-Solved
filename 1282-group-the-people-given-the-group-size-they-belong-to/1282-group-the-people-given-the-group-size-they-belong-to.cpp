class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        
        vector<pair<int,int>> a;
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            a.push_back({groupSizes[i],i});
        }
        
        sort(a.begin(),a.end());
        
        for(int i=0;i<n;i++){
            
            vector<int> b;
            
            b.push_back(a[i].second);
            
            int count=0;
            
            for(int j=i;j<n-1;j++){
                if(a[j].first==a[j+1].first){
                    if(b.size()==a[i].first){
                        break;
                    }
                    b.push_back(a[j+1].second);
                    count++;
                }
                else{
                    break;
                }
            }
            ans.push_back(b);
            i+=count;
        }
        return ans;
    }
};
