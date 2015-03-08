/*
 * =====================================================================================
 *
 *       Filename:  package_system.h
 *
 *    Description:  Design a package tracking system
 *                  Need implement poerations: find, add and remove packages
 *
 *        Created:  03/08/2015 15:09:30
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

class Package{
    public:
        Package(Customer &_owner, string &_from_add, string &_to_add, string &_no) : 
            owner(_owner), from_add(_from_add), to_add(_to_add), tracking_no(no){}
    
        Customer getOwner();
        string get_to_add(); 
        string get_tracking_no();

    private:
        Customer owner;
        string from_add;
        string to_add;
        string tracking_no;
};

class Customer{
    public:
        Customer(string &_name, string &_add) : name(_name), add(_add){}
    
        string getName();
        string getAdd();

    private:
        string name;
        string add;
};

class TrackingSystem{
    public:
        TrackingSystem(){}

        void addPackage(Package &p);
        void removePackage(Package &p);
        
        // find a package given a tracking no
        Package* find_package(string &tracking_no){
            if(packages.find(tracking_no) == packages.end()){
                return nullptr;
            } 

            return packages[tracking_no];
        }

    private:
        unordered_map<string, Package*> packages;
};


