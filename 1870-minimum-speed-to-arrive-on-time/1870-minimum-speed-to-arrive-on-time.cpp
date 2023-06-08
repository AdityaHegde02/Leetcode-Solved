class Solution {
public:
    bool isPossible(vector<int> &dis,int mid,double h){
        double totalTime = 0;
        for(int i = 0; i < dis.size(); i++){
            if(i != dis.size() - 1){
                totalTime += ceil((double)dis[i]/(double)mid);
            }
            else{
                totalTime += ((double)dis[i])/(double)mid;
            }
        }    
        
        return (totalTime <= h);
    }
    
    int minSpeedOnTime(vector<int>& dis, double hours) {
        int l = 0, h = 1e7,ans = -1;
        while(l <= h){
            int mid = l + (h - l)/2;
            if(isPossible(dis,mid,hours)){
                ans = mid;
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};