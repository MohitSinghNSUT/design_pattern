#include<iostream>
using namespace std;
class student{
public:
string name;
int age;
float gpa ;
};
int main(){
    // way 1 --->>
student mohit ={"mohit",19,8.25};
    // way 2 --->>
student b;
b.name="b";
b.age=10;
b.gpa=1.9;

return 0;
}