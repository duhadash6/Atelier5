#include <iostream>
using namespace std;

class erreur {
public:
    int num;
};

class A {
public:
    A(int n) {
        if (n == 1) {
            erreur er;
            er.num = 999;
            throw er;
        }
    }
};

void f();

int main() {
    try {
        f();
    }
    catch (erreur er) {
        cout << "dans main : " << er.num << "\n";
    }
    cout << "suite main\n";
}

void f() {
    try {
        A a(1);
    }
    catch (erreur er) {
        cout << "dans f : " << er.num << "\n";
    }
}