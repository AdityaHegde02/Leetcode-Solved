class Solution {
public:
    string intToRoman(int num) {
        string ans;
        unordered_map<int,string> mp = {  {1,"I"},   
                                        {4,"IV"},
                                        {5,"V"},  
                                        {9,"IX"},
                                        {10,"X"}, 
                                        {40,"XL"},
                                        {50,"L"},   
                                        {90,"XC"},
                                        {100,"C"},  
                                        {400,"CD"},
                                        {500,"D"},
                                        {900,"CM"},
                                        {1000,"M"} };
        
        vector<int> nums{1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        while(num!=0){
            for( int i=0; i< 13 ;i++){
                if(num>=nums[i]){
                    ans += mp[nums[i]];
                    num -= nums[i];
                    break;
                }
            }
        }
        return ans;
    }
};