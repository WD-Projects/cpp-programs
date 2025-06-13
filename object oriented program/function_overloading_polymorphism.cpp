#include <iostream>
#include <string>
using namespace std;
class Print {
public:
    void same(int x) {
        cout << "int: " << x << endl;
    }

    void same(string x) {
        cout << "string: " << x << endl;
    }
};

int main() {
    Print p1;
    // p1.same(2); // this will print int value
    p1.same("mahir"); // this will print string value
}