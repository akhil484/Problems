class ParkingSystem {
public:
    int bigCar, mediumCar, smallCar;
    ParkingSystem(int big, int medium, int small) {
        bigCar=big;
        mediumCar= medium;
        smallCar=small;
    }
    
    bool addCar(int carType) {
        if((carType==1&&bigCar==0)||(carType==2&&mediumCar==0)||(carType==3&&smallCar==0))
            return false;
        else if(carType==1)
            bigCar--;
        else if(carType==2)
            mediumCar--;
        else
            smallCar--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */