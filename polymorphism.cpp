#include <iostream>
using namespace std;
class polymorphism
{
private:
public:
    polymorphism()
    {
    }
    ~polymorphism()
    {
    }
    // function overloading only happen using the arguments 
    int f(int a)
    {
        return 1;
    }
    int f()
    {
        return 0;
    }
    // we cannot do overloading by return type
    // ***************************************
    // char f(){
    //     return 'c';
    // }
    // ***************************************
    // function overloading using virtual keyword
    virtual int changeName()
    {
        cout << "change Name in above function\n";
        return 0;
    }
    // ***************************************
};
class Vector
{
public:
    int x, y;
    // Overloading the '+' operator as a member function
    Vector operator+(const Vector &other)
    {
        Vector result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }
};
class childName : public polymorphism
{
public:
    // function overriding we are making the function to change when ever the inherit the class
    int changeName()
    {
        cout << "change Name in above function 1 \n";
        return 0;
    }
};
int main()
{
    childName *cn = new childName();
    cn->changeName();
    // Usage:
    Vector v1{1, 2}, v2{3, 4};
    Vector v3 = v1 + v2; // Calls v1.operator+(v2)
    cout<<v3.x<<" "<<v3.y<<'\n';
}
