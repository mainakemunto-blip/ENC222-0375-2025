#include <iostream>
using namespace std;

int main() {
    int numbers[20];
    int even[20], odd[20];
    int evenCount = 0, oddCount = 0;

for (int i = 0; i < 20; i++) {
    numbers[i] = (i + 1);  
}
for (int i = 0; i < 20; i++) {
if (numbers[i] % 2 == 0) {
even[evenCount] = numbers[i];
    evenCount++;}
else {
odd[oddCount] = numbers[i];
    oddCount++;
}
}
cout << "Even numbers: ";
for (int i = 0; i < evenCount; i++) {
cout << even[i] << " ";
}
cout << "\nOdd numbers: ";
for (int i = 0; i < oddCount; i++) {
cout << odd[i] << " ";
}
return 0;
}
