#include <iostream>
using namespace std;
class student
{ // encapsulation
private:
    int age;
    string name;
    vector<string> subjects;
    int rollnumber;

public:
    void setAge(int age)
    {
        this->age = age;
    }
    int getAge()
    {
        return this->age;
    }
};
// when all data members and properties are private = fully encapsulated class
class library
{
};

class placement
{
};
class hostel
{
};
class regularStudent : public student
{ // regular degree
    // they will have access to placements and library and various
    library *lib;
    placement *placement;
    hostel *hostel;

public:
};

class onlineStudent : public student
{ // this is enrolled for a online degree
public:
    // they only have access to classes in online mode
};

//******************************************************************************************************************************************

// parent child
//----------------
// public public -> every where
// public protected -->(protected) if we create an object of  child then we can not access the parent protected main but can be access in further child creation
// public private  --> (private) if we create an object of child then we can not access the parent private main and can not be access in further child creation
//----------------
// protected public -> (protected) // can be used only in the child of the current class
// protected protected  -> (protected) // can be used only in the child of the current class
// protected private -> (private) can be access inside the current class only
//----------------
// private public --> no inheritance
// private protected -->no inheritance
// private private  -->no inheritance

//******************************************************************************************************************************************

// 1) constructor of super class is called first and then child class
// 2) constructor are always ** public **

// EXAMPLE OF SINGLE INHERITANCE
class human
{
public:
    string name;
    int age;
    human()
    {
        cout << "i am human first \n";
    }
};
class male : public human
{
public:
    male()
    {
        cout << "i am male second \n";
    }
};
class female : public human
{
public:
    female()
    {
        cout << "i am female second \n";
    }
};

class donkey
{
public:
    int age;
    donkey()
    {
        cout << "donkey\n ";
    }
};
class horse
{
public:
    int age;
    horse()
    {
        cout << "horse \n";
    }
};

// multiple inheritance
class mule : public horse, public donkey
{ // there constructor will be called in order they are inherited
public:
    mule()
    {
        // age is now available from both so this is diamond problem and solved using :: operator
        cout << horse::age << '\n';
        cout << "mule\n";
    }
};
// multilevel inheritance
class A
{
public:
    A()
    {
        cout << "A\n";
    }
};
class B : public A
{
public:
    B()
    {
        cout << "B\n";
    }
};
class C : public B
{
public:
    C()
    {
        cout << "C\n";
    }
};

int main()
{
    female *f = new female();
    mule *m = new mule();
    C *c = new C();
}
