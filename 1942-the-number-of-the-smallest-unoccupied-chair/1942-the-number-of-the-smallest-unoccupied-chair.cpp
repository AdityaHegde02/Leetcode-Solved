class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        set<int> chairs;
        int n = times.size();

        for(int i = 0; i<n; i++)
        {
            chairs.insert(i);
        }

        vector<vector<int>> t;

        for(int i = 0; i<n; i++)
        {
            int arr = times[i][0];
            int dep = times[i][1];

            t.push_back({arr, 1, i});
            t.push_back({dep, 0, i});
        }

        sort(t.begin(), t.end());

        vector<int> ans(n, 0);

        for(int i = 0; i<t.size(); i++)
        {
            if(t[i][1] == 1) // arrival
            {
                int ch = *chairs.begin();
                ans[t[i][2]] = ch;
                chairs.erase(ch);
            }
            else
            {
                int ch = ans[t[i][2]];
                chairs.insert(ch);
            }
        }

        return ans[targetFriend];
    }
};                   