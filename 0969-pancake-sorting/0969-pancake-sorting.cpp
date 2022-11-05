class Solution {
public:
    int getIdx(int num,vector<int> &arr){
        for(int i = 0;i < arr.size(); i++){
            if(arr[i] == num){
                return i;
            }
        }
        return -1;
    }
    
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        vector<int> sorted = arr;
        sort(sorted.begin(),sorted.end());
        
        int i = arr.size() - 1;
        
        while(i >= 0){
            int pos = getIdx(sorted[i],arr);
            reverse(arr.begin(), arr.begin() + pos + 1);
            reverse(arr.begin(), arr.begin() + i + 1);
            ans.push_back(pos + 1);
            ans.push_back(i + 1);
            i--;
        }
        
        return ans;
    }
};