#include <iostream>
using namespace std;
class Employee{
private:
  string name;
  int age;
  int serviceyear;
  double salary;
public:
  Employee(string n, int a, int sy, double sal){
  name=n;
  age=a;
  serviceyear=sy;
  salary=sal;
  }
~Employee(){
 }
};