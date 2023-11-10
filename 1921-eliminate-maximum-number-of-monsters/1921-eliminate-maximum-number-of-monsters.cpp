class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> times;
        for(int i = 0; i < dist.size(); i++){
            if((dist[i] % speed[i]) != 0){
                times.push_back((dist[i]/speed[i]) + 1);
            }
            else{
                times.push_back((dist[i]/speed[i]));
            }
        }
        
        sort(times.begin(),times.end());

        int lasthit = 0;
        for(int i = 0; i < dist.size(); i++){
            if(lasthit < times[i]){
                lasthit++;
            }
            else{
                return i;
            }
        }
        
        return dist.size();
    }
};