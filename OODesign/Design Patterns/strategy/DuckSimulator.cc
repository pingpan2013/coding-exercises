/*
 * =====================================================================================
 *
 *       Filename:  DuckSimulator_strategy.h
 *
 *    Description:  A duck simulator using strategy patterns
 *
 *        Created:  01/06/2015 23:53:28
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

/*
 Design principles:
 1. Separate the constant and always chaning features;
 2. Program to an interface instead of an implementation
 3. Favor object composition over class inheritance
*/


/**
 * Strategy Pattern:
 * Design class for behaviors and make use of aggregation or composition to integrate
 * the behavior class 
 */

#include <iostream>

using namespace std;

// Interfaces for behaviors
class FlyBehavior{
  public:
    virtual void fly() = 0;
};

class QuackBehavior{
 public:
    virtual void quack() = 0; 
};


// Implementing interface FlyBehavior
class FlyWithWings : public FlyBehavior{
  public:
    void fly(){
        cout << "I'm flying!" << endl;
    }
};

class FlyNoWay : public FlyBehavior{
  public:
    void fly(){
        cout << "I cannot fly!!" << endl;
    }
};

// Implementing interface Quackbehavior
class Quack : public QuackBehavior{
public:
    void quack(){
        cout << "Quack" << endl;
    }
};

class MuteQuack : public QuackBehavior{
public:
    void quack(){
        cout << "<< Silence >>" << endl;
    }
};


// Base class: Duck
class Duck{
  public:
    Duck(){};
    
    //virtual void display();  // Error, must be implemented
    virtual void display(){
        cout << "I am a duck!" << endl;
    };
    
    void swim(){
        cout << "All ducks float, even decoys" << endl;
    };
    
    // Let the class of behavior to implement these functionalities
    void performFly(){
        fb->fly();
    };

    void performQuack(){
        qb->quack();
    }
    
    // setter methods
    // Dynamically change the methods used
    void setFlyBehavior(FlyBehavior *_fb){
        fb = _fb;
    }

    void setQuackBehavior(QuackBehavior *_qb){
        qb = _qb;
    }

    FlyBehavior *fb;    // aggregation
    QuackBehavior *qb;  // aggregation
};


class MallardDuck : public Duck{
public:
    MallardDuck(){
        fb = new FlyWithWings();
        qb = new Quack();
    }

    void display(){
        cout << "I am a real Mallard Duck!" << endl;
    }
};


// TEST
int main(){
    Duck *mallard = new MallardDuck();
    mallard->display();
    mallard->performQuack();
    mallard->performFly();

    // using the setter method to dynamically change the method
    mallard->setFlyBehavior(new FlyNoWay());
    mallard->performFly();

    return 0;
}


