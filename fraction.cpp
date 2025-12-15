#include <iostream>
using namespace std;
struct Fraction {
    int numerator;
    int denominator;
};
Fraction& largestFraction(Fraction&f1,Fraction&f2,Fraction&f3){
    double value1=f1.numerator/f1.denominator;
    double value2=f2.numerator/f2.denominator;
    double value3=f3.numerator/f3.denominator;
if (value1>=value2 and value1>=value3)
  return f1;
else if (value2>=value1 and value2>=value3)
  return f2;
else 
  return f3;
}
int main(){
    Fraction f1={2,3};
    Fraction f2={4,5};
    Fraction f3={10,1};
Fraction& largest=largestFraction(f1,f2,f3);
cout << "Largest fraction is "
     << largest.numerator << "/" << largest.denominator << endl;

return 0;
}
