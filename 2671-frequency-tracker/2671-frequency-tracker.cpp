class FrequencyTracker {
public:
    unordered_map<int,int> mp;
    unordered_map<int,int> counts;
    
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(mp.find(number) == mp.end()){
            if(counts.find(1) == counts.end()){
                counts[1] = 1;
            }
            else{
                counts[1]++;
            }
            
            mp[number] = 1;
        }
        else{
            counts[mp[number]]--;
            mp[number]++;
            counts[mp[number]]++;
        }
    }
    
    void deleteOne(int number) {
        if(mp.find(number) != mp.end()){
            counts[mp[number]]--;
            mp[number]--;
            counts[mp[number]]++;
            if(mp[number] == 0){
                mp.erase(number);
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return (counts[frequency]);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */