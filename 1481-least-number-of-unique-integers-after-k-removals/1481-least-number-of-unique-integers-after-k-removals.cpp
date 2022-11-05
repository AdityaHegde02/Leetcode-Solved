class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(auto &i : arr){
            mp[i]++;
        }
        vector<int> counts;
        for(auto &pair: mp){
            counts.push_back(pair.second);
        }
        
        sort(counts.begin(),counts.end());
        int i = 0;
        while(k){
            if(k - counts[i] >= 0){
                k -= counts[i++];
            }
            else{
                break;
            }
        }
        return (counts.size() - i);
    }
};