class Solution {
public:
    bool isPossible(int mid,vector<int> &w,int days){
        int d = 1;
        int curr = 0;
        for(int i = 0; i < w.size(); i++){
            if(w[i] > mid){
                return false;
            }
            else if(curr + w[i] > mid){
                d++;
                curr = 0;
                i--;
            }
            else{
                curr += w[i];
            }
        }
        
        if(d <= days){
            return true;
        }
        return false;
    }
    
    int shipWithinDays(vector<int>& w, int d) {
        int sum = accumulate(w.begin(),w.end(),0);
        int low = 0;
        int high = sum;
        int cap = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(mid,w,d)){
                cap = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return cap;
    }
};