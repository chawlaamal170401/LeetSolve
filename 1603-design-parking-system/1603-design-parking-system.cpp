class Park{
public:
    int m, s, b;
};
class ParkingSystem {
public:
    Park p;
    ParkingSystem(int big, int medium, int small) {
        p.b = big;
        p.m = medium;
        p.s = small;
    }
    
    bool addCar(int carType) {
        bool flag;
        switch(carType){
            case 1: 
                flag = p.b > 0 ? true : false;
                p.b -= 1;
                break;
            case 2:
                flag = p.m > 0 ? true : false;
                p.m -= 1;
                break;
            case 3:
                flag = p.s > 0 ? true : false;
                p.s -= 1;
                break;
        }
        return flag;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */