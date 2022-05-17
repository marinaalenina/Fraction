#include "Header.h"

using namespace std;


int main() {
    Fraction f1(2, 4);
    Fraction f2, f3, f4, f5, f6, f7;


    cout << "Enter the fraction: ";
    cin >> f2;
    f3 = f2 - f1;
    f4 = f1 * f2;
    cout << "\n(" << f2 << " - " << f1 << ") / 2 = " << f3 / 2 << "\n\n";
    cout << "(" << f1 << " * " << f2 << ") + 3 = " << f4 + 3 << "\n\n";


    cout << "Enter the first fraction: ";
    cin >> f5;
    cout << "Enter the second fraction: ";
    cin >> f6;
    if (f5 > f6)
        cout << f5 << " is higher than " << f6 << "\n\n";
    else
        cout << f5 << " is lower than " << f6 << "\n\n";


    float f = f3;
    cout << "Float version " << f3 << " is: " << f << "\n\n";
    double d = f4;
    cout << "Double version " << f4 << " is: " << d << "\n\n";

    return 0;
}