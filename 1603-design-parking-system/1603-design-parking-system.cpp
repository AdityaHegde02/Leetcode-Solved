class ParkingSystem {
public:
    vector<int> park;
    ParkingSystem(int big, int medium, int small) {
        park.push_back(big);
        park.push_back(medium);
        park.push_back(small);
    }
    
    bool addCar(int carType) {
        if(park[carType-1]){
            park[carType-1]--;
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */