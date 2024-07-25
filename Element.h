#ifndef ASSIGNMENT3_ELEMENT_H
#define ASSIGNMENT3_ELEMENT_H


#include <iostream>

   using namespace std;

class Player;
class Element { //it will be abstract class
    protected:
    int size;
    char representBoard;
    char effect;


public:
    Element();

    Element(int size);
    

    virtual void Effect (Player& player) = 0; //it becomes pure virtual function
    ~Element (){} //destructor
};


class Food : public Element{ //inheritance
public:
    Food(int size){}
     void Effect (Player& player);

};


class Wood : public Element{ //inheritance
public:
    Wood(int size) {}
    void Effect (Player& player);

};

class MedicalSupplies : public Element{ //inheritance
public:
    MedicalSupplies(int effect){}
    void Effect (Player& player);

};

class WildAnimals : public  Element{ //inheritance
public:
    WildAnimals(int size, char represent, char effect){ //parametize constructor
        this->representBoard = represent;
        this->effect = effect;
    }

    virtual void Effect (Player& player) = 0; // Pure virtual method -> this is also an abstract function and must be defined by subclasses.

};

class Wolf : public WildAnimals{ //inheritance
public:
    Wolf(int effect) : WildAnimals(1, 'W', 'D') {} // Constructor method for the wolf object
    void Effect (Player& player); //wolf's effect function
};

class Bear :public WildAnimals{ //inheritance
public:
    Bear(int effect) : WildAnimals(3, 'B', 'D'){} // Constructor method for the wolf object
    void Effect (Player& player); //bear's effect function

};


class Gold : public Element{ //inheritance
public:
    Gold() {} //default constructor
    void Effect (Player& player); //gold's effect function

};

#endif //ASSIGNMENT3_ELEMENT_H