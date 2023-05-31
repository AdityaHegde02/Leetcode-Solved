class UndergroundSystem {
public:
    unordered_map<string,pair<int,double>> mp;
    unordered_map<int,pair<string,int>> in;
    
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = in[id].first;
        int startTime = in[id].second;
        double time = (t - startTime);
        string temp = startStation + ":" + stationName;
        if(mp.find(temp) == mp.end()){
            mp[temp] = {1,time};
        }
        else{
            mp[temp] = {mp[temp].first + 1,mp[temp].second + time};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string temp = startStation + ":" + endStation;
        double ans = (double)(mp[temp].second)/mp[temp].first;
        return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */