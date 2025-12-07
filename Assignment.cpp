#include <iostream>
using namespace std;

class Friend {
public:
    string x;
    string y;

    Friend(string a, string b) {
        this->x = a;
        this->y = b;
    }

    void display_info() {
        cout << "Joy is an " << x << " and " << y << " friend." << endl;
    }
};

int main() {
    Friend Joy("honest", "trustworthy");
    Joy.display_info();

    return 0;
}
//1.difference between float and double and character and string
//float is used to store decimal numbers and used 4 bytes of memory which can only store 6-7 decimal digits accurately while a double is used to store decimal numbers and used 8 bytes memory which is used to store up to 17 decimals digits accurately.
//Character represents a single letter, digit, symbol or single unit of text while a string represents a sequence of zero or more characters.
//2.#include<iostream> /n using namespace standard
//#include is a preprocessor directive.
//<iostream> is a header file in C++ that contains input and output streams like cout(output) and cin(input) that enable one to output and input code.
//Namespace standard  stores standard library features like cout, cin, string.

