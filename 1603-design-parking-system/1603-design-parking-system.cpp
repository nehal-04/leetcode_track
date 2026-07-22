class ParkingSystem {
public:
    vector<int>park_spots;
    ParkingSystem(int big, int medium, int small) {
        park_spots.resize(3);
        park_spots[0] = big;
        park_spots[1]=medium;
        park_spots[2] = small;
    }
    
    bool addCar(int carType) {
        if(park_spots[carType-1] >0){
            park_spots[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */