class Solution {
public:
    int smallestChair(vector<vector<int>>& t, int tF) {
        int currTime = 1;
        
        // map of at this time who arrives
        unordered_map<int,int> arrive;
        for(int i = 0; i < t.size(); i++){
            arrive[t[i][0]] = i;
        }
        
        //map of at this time who all departures
        unordered_map<int,vector<int>> dep;
        for(int i = 0; i < t.size(); i++){
            dep[t[i][1]].push_back(i);
        }
        
        set<int> seats;
        for(int i = 0; i < t.size(); i++){
            seats.insert(i);
        }
        
        // map of who all are in which seat
        unordered_map<int,int> mapping;
        
        while(true){
            // remove all empty chairs at that time
            for(auto &i : dep[currTime]){
                seats.insert(mapping[i]);
            }
            // add arrival to first empty seat
            if(arrive.count(currTime)){
                int s = *seats.begin();
                // cout << s << endl;
                if(arrive[currTime] == tF)
                    return s;
                mapping[arrive[currTime]] = s;
                seats.erase(s);
            }
            
            currTime++;
        }
        
        return -1;
    }
};                       