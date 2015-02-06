/*
 * =====================================================================================
 *
 *       Filename:  singleton.cc
 *
 *    Description:  singleton design pattern
 *
 *        Created:  02/05/2015 21:54:12
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <cassert>

class Singleton{
public:
    static Singleton* getInstance();  // should be static

private:
    Singleton() {}  // Attention, should contain implementation
    static Singleton *instance;   // should be static
};

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance(){
    if(instance){
        return instance;
    }

    instance = new Singleton();
    return instance;
}

int main(){
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();

    assert(instance1 == instance2 && "Failed test case!");
    
    return 0;
}
