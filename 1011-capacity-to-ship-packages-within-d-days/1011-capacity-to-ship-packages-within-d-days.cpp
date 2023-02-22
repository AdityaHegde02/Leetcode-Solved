class Solution {
public:
    bool possiblecapacity(vector<int>& w,int cap,int d){
        
        int mxsum=cap,currsum=0;
        for(int i=0;i<w.size();++i){
            if(currsum+w[i]<=mxsum){
                currsum+=w[i];
                if(d==1 and i==w.size()-1){
                    return true;
                }
            }
            else if(d>0){
                currsum=0;
                d--;
                i--;
                if(d==0 and i!=w.size()-1){
                    return false;
                }
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& w, int d) {
        int mx=INT_MIN,sum=0,ans=0;
        for(int i=0;i<w.size();++i){
            sum+=w[i];
            mx=max(w[i],mx);
        }
        for(int i=mx;i<=sum;i++){
            if(possiblecapacity(w,i,d)){
                return i;
            }
        }
        return -1;
    }
};