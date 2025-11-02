#include <iostream>
using namespace std;
class Talk
{
public:
    Talk()
    {
    }
    virtual void talk() = 0;
};

class NoTalk : public Talk
{
public:
    NoTalk()
    {
    }
    void talk()
    {
        cout << "not able to talk" << '\n';
    }
};
class FastTalk : public Talk
{
public:
    FastTalk()
    {
    }
    void talk()
    {
        cout << "able to talk" << '\n';
    }
};
class Walk
{
public:
    Walk()
    {
    }
    virtual void walk() = 0;
};
class NoWalk : public Walk
{
public:
    NoWalk()
    {
    }
    void walk()
    {
        cout << "not able to walk" << '\n';
    }
};
class FastWalk : public Walk
{
public:
    FastWalk()
    {
    }
    void walk()
    {
        cout << "able to walk" << '\n';
    }
};
class See
{
public:
    See()
    {
        cout << "all can see \n"
             << '\n';
    }
};
class Robot
{
    Walk *w;
    Talk *t;
    See *s; //  instead of making see an property of the robot class we are making see as an class and then making a pointer in it

public:
    Robot(Walk *w, Talk *t)
    {
        this->w = w;
        this->t = t;
    }
    void properties()
    {
        w->walk();
        t->talk();
    }
};
int main()
{
    Robot *r = new Robot(new NoWalk(), new FastTalk());
    r->properties();
}
