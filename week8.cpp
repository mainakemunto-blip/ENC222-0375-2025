#include <iostream>
using namespace std;
// Base class
class Square{
protected:
    double side;
public:
    // Constructor
    Square(double s=0){
        side=s;
    }
    // Destructor
    ~Square(){
    }
    double getPeri(){
        return 4*side;
    }
    double getArea(){
        return side*side;
    }
};

// Derived class
class Cube:public Square{
public:
    // Constructor
    Cube(double s=0) : Square(s){
    }
    // Destructor
    ~Cube(){
    }
    double getArea(){
        return 6*side*side;
    }

    double getVolume(){
        return side*side*side;
    }
};

int main() {
    Square sq(15);
    cout <<"Square Perimeter:"<<sq.getPeri()<<endl;
    cout <<"Square Area:"<< sq.getArea()<<endl;

    Cube cb(15);
    cout << "Cube Surface Area:"<<cb.getArea()<<endl;
    cout << "Cube Volume:"<<cb.getVolume()<<endl;

    return 0;
}
