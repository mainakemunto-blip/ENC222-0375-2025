#include <iostream>
using namespace std;
struct Car{
    int milage;
    string type;
    string model;
};
int main(){
    Car myCar={200,"Toyota","Corolla"};
cout<<"My car is a "<< myCar.type
    <<" with model "<< myCar.model
    <<" and a milage of "<< myCar.milage<<".\n";
//selection statement
if (myCar.milage>200)
   cout<<"the car is economical.\n";
else 
   cout<<"the car is not econimical.\n";
//iteration statement
cout<<"\nrepeating car type 5 times:\n";
for (int a=0; a<5; a++)
cout<<myCar.type<<"\n";
return 0;
}
