class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while(s.size()>1){
            if(s.back()=='0'){
                s.pop_back();
                steps++;
                continue;
            }
            bool check=false;
            for(int i=s.size()-1;i>=0;i--){
                if(s[i]=='0'){
                    steps++;
                    s[i]='1';
                    check=true;
                    break;
                }
                s[i]='0';
            }
            if(!check){
                s='1'+s;
                steps++;
            }
        }
        return steps;
    }
};
  
        
//         signed long long int num=0,n=s.length();
//         long long int count=0;
        
//         for(int i=n-1;i>=0;i--){
//             char c=s[i];
//             int b=c-'0';
//             signed long long int mul=pow(2,count);
//             num+=mul*(b);
//             count++;
//         }
//         cout<<num;
        
//         int ans=0;
//         while(num>1){
//             if(num%2==0){
//                 num/=2;
//             }
//             else{
//                 num++;
//             }
//             ans++;
//         }
//         return ans;