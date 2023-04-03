class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        int l = 0, r = n - 1, ans = 0;
        while(l <= r){
            if(people[l] + people[r] <= limit){
                ans++;
                l++;
                r--;
            }
            else{
                ans++;
                r--;
            }
        }
        return ans;
    }
};