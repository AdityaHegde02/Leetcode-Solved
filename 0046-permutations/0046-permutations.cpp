class Solution {
public:
    vector<vector<int>> ans;

    void generate( vector<int> &nums , vector<int> &temp ,vector<int> &visited){
        
        if( temp.size() == nums.size() ){
            visited[temp.back() + 10] = 0 ;
            ans.push_back( temp );
            temp.pop_back();
            return ;
        }
        
        for( int i = 0 ; i < nums.size() ; i++ ){
            if( !visited[nums[i]+10] ){
                temp.push_back(nums[i]);
                 visited[nums[i] + 10] = 1;
                generate( nums , temp ,visited);
                visited[nums[i]+10] = 0;
            }
        }
        temp.pop_back();
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        
        vector<int> visited(21,0);
    
        generate( nums,temp,visited );
        
        return ans;
    }
};