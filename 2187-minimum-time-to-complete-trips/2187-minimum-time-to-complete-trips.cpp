class Solution {
public:
    long long minimumTime(vector<int>& time, int T) {
        long long int abs = 0;
        long long int lt = 0,ht = 1e14,n = time.size();
        
        // vector<long long int> copy(n,0);
        
        long long int mid;
        while(lt <= ht){
            mid = (lt+ht)/2;
            // cout<<ht<<" "<<lt<<" "<<mid<<endl;
            long long int sum = 0;
            for(int i = 0; i < n; i++){
                sum += (mid/time[i]);
                // sum+=copy[i];
            }
            
            // long long int sum = 0;
            // for(int &i : copy){
            //     sum += i;
            // }
            
            if(sum >= T){
                abs = mid;
                ht = mid - 1;
            }
            else{
                lt = mid + 1;
            }
        }
        
        return abs;
    }
};