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
