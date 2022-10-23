class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> x;

    void generate( vector<int> &nums , vector<int> &temp ,vector<int> &visited){
        
        if( temp.size() == nums.size() ){
            int y = temp.back();
            if(x.find(temp) == x.end()){
                ans.push_back( temp );
                x.insert(temp);
            }
            temp.pop_back();
            return ;
        }
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            if( !visited[i] ){
                temp.push_back(nums[i]);
                visited[i] = 1;
                generate( nums , temp ,visited);
                visited[i] = 0;
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        
        vector<int> visited(8,0);
    
        generate( nums,temp,visited );
        
        return ans;
    }
};