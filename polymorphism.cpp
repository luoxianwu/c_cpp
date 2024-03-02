#include <iostream>
#include <string>
using namespace std;

class Shape{
    string name;
    public:
    Shape( string _nm) { name = _nm; }   
    string & getName(){ return name; }
    virtual double getArea() = 0;
};

class Circle : public Shape{
    double radius;
    public:
    /* call constructor of base class */
    Circle( string _nm, int _r) : Shape(_nm) {radius = _r;}
    /* derived class must provide the pure virtual functuin, defined by base class*/
    double getArea() { return (radius * radius * 3.14); }
};

int main()
{
    /* once there is pure virtual functuin in the class, it is not instantiable*/
    //Shape s("shape");
    //cout << s.getName() << endl;

    Circle c("cricle", 3);
    cout << c.getName() << endl;
    cout << c.getArea() << endl;

}
