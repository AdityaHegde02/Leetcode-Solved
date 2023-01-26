class Bank {
public:
    vector<long long int> acc;
    
    Bank(vector<long long>& balance) {
        acc = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > acc.size() or account2 > acc.size()){
            return false;
        }
        bool f = withdraw(account1,money);
        if(!f){
            return false;
        }
        deposit(account2,money);
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > acc.size()){
            return false;
        }
        acc[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > acc.size()){
            return false;
        }
        if(acc[account - 1] - money < 0){
            return false;
        }
        acc[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */