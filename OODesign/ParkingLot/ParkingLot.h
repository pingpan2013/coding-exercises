/*
 * =====================================================================================
 *
 *       Filename:  ParkingLot.h
 *
 *    Description:  Design a parking lot class using OOD
 *
 *        Created:  10/28/2014 11:55:26
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#define NUM_OF_LEVELS 5

class ParkingLot{
    public:
        ParkingLot(){
            Levels.resize(NUM_OF_LEVELS);
        }

        static ParkingLot* getInstance();   // for getting the unique instance in singleton 
        bool parkVehicle(Vehicle &v);
        void unparkVehicle(Vehicle &v);

    private:
        static ParkingLot* pInstance;       // used for singleton design pattern
        vector<Level> levels;
};

class Level{
    public:
        bool isFull();
        int findParkingSpot(Vehicle &v);            // find parking spot for a vehicle, return the spotNo
        bool parkStartingAt(int num, Vehicle &v);   // return false if failed
        void freeSpot();                            // free spot when the vehicle is removed 

    private:
        int levelNo;
        int free_spots = 0;
        vector<ParkingSpot> spots;
        const int TOTAL_SPOTS = 100;
};

class ParkingSpot{
    public:
        ParkingSpot(Level _level, _spotNo): 
            Level(_level), spotNo(_spotNo) {  }
        
        virtual ~ParkingSpace(){}

        virtual park(Vehicle &v);
        virtual removeVehicle();

        virtual bool isFree(){
            // check if vehicle is initialized
        }
        
        int getSpotNo();

    private:
        Vehicle vehicle;
        bool state;
        int rowNo;
        int spotNo;
        Level level;
};

class RegularParkingSpace: public ParkingSpot{}
class HandicappedParkingSpace: public ParkingSpot{}
class CompactParkingSpace: public ParkingSpot{}


class Vehicle{
    public:
        Vehicle(){}
        virtual ~Vehicle(){}
        
        // check status
        virtual bool isParked();

    private:
        bool parked;

    protected:
        string plateNo;
};

class Motorbike: public Vehicle{}
class Car: public Vehicle{}
class Bus: public Vehicle{}

