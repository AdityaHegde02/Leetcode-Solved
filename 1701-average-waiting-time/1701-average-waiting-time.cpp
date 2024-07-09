class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0;
        int time = customers[0][0], cus = customers.size();
        for(int i = 0; i < cus; i++){
            int order = customers[i][1];
            int arrive = customers[i][0];
            if(arrive > time){
                wait += (order);
                time = arrive + order;
            }
            else{
                wait += (time + order - arrive);
                time += order;
            }
        }
        return (double)wait/cus;
    }
};