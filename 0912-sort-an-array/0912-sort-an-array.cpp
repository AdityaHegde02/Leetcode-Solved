const static auto fast=[]{
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
return 0;
}();

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int minNum=nums[0], maxNum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>maxNum)
                maxNum=nums[i];
            if(nums[i]<minNum)
                minNum=nums[i];
        }
		
		// Make a frequency array to store frequency of each element of original array.
		
        vector<int> freq_arr(maxNum-minNum+1, 0);
        for(int i=0;i<nums.size();i++)
            freq_arr[nums[i]-minNum]++;
			
		// Making it a prefix sum array, so it stores the last poition of each element.
		
        for(int i=1;i<freq_arr.size();i++)
            freq_arr[i]+=freq_arr[i-1];
			
		// Decrementing 1 to get index (as arrays start from 0). 
			
        for(int i=0;i<freq_arr.size();i++)
            freq_arr[i]--;
        
		// Start traversing from last element, and put the numbers in respected index (index obtained from freq index) and decrement each entry of fre_index by 1.
		
        for(int i=nums.size()-1;i>=0;i--)
        {
            result[freq_arr[nums[i]-minNum]]=nums[i];
            freq_arr[nums[i]-minNum]--;
        }
        return result;
    }
};