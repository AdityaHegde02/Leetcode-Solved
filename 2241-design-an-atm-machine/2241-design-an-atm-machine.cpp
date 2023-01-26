class ATM {
public:
    vector<long long int> notes,val;
    
    ATM() {
        for(int i = 0; i < 5; i++){
            notes.push_back(0); val.push_back(0);
        }
        val[0] = 20;
        val[1] = 50;
        val[2] = 100;
        val[3] = 200;
        val[4] = 500;
    }
    
    void deposit(vector<int> count) {
        for(int i = 0; i < 5; i++){
            notes[i] += count[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<long long int> temp = notes; 
        vector<int> ans(5,0);
        for(int i = 4;i >= 0; i--){
            if(notes[i]){
                int countOfNotes = (amount/val[i]);
                if(countOfNotes > notes[i]){
                    countOfNotes = notes[i];
                }
                amount -= ((long long)val[i]*(countOfNotes));
                ans[i] = countOfNotes;
                temp[i] -= countOfNotes;
                if(amount <= 0){
                    break;
                }
            }
        }
        if(amount == 0){
            swap(notes,temp);
            return ans;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */