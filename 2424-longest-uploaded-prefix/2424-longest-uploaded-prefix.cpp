class LUPrefix {
public:
    vector<int> videos;
    int last = 0;
    
    LUPrefix(int n) {
        for(int i = 0; i <= n; i++){
            videos.push_back(0);
        }
    }
    
    void upload(int video) {
        videos[video] = 1;
    }
    
    int longest() {
        for(int i = last + 1; i < videos.size(); i++){
            if(videos[i] == 0){
                last = i - 1;
                return last;
            }
        }
        return last = videos.size() - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */