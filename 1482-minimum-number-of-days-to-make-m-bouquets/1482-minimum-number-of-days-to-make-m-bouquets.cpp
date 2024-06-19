class Solution {
public:
    int getBouq(vector<int>& bloomDay,int day,int k){
        int result=0,count=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
                count++;
            else
                count=0;
            if(count==k)
                result++,count=0;
        }
        return result;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        auto p=minmax_element(bloomDay.begin(),bloomDay.end());
        int j=*p.second,i=*p.first;
        int mid;
        while(i<j)
        {
            mid=(i+j)>>1;
            if(getBouq(bloomDay,mid,k)<m)
                i=mid+1;
            else
                j=mid;
        }
        return getBouq(bloomDay,i,k)>=m?i:-1;
    }
};