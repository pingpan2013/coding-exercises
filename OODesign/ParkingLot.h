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


class ParkingLot{
    private:
        int max_lvl;
        static ParkingLot* pInstance;       // used for singleton design pattern
        std::multimap<int, Level*> allLevels;
    public:
        static ParkingLot* getInstance();   // for getting the unique instance in singleton 
};

class Level{
    private:
        int max_num;
        std::map<int, ParkingSpace*> eachLevel;
    public:
        int getFirstParkingSpace();
        bool isFull();
        bool isEmpty();
};



class ParkingSpace{
    private:
        bool state;
        int index;
    public:
        virtual bool isFree();
        virtual ~ParkingSpace(){}
};
class RegularParkingSpace: public ParkingSpace{}
class HandicappedParkingSpace: public ParkingSpace{}
class CompactParkingSpace: public ParkingSpace{}


class Vehicle{
    private:
        bool parked;
    public:
        virtual bool isParked();
        virtual ~Vehicle(){}
};
class Motorbike: public Vehicle{}
class Car: public Vehicle{}
class Bus: public Vehicle{}


class Parker{
    public:
        void parkVehicle(Vehicle *veh, ParkingSpace *s);
        void unparkVehicle(Vehicle *veh, ParkingSpace *s);
};


