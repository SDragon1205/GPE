#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

int main(void) {
    double x = (4 * M_PI - 12 * sqrt(3) + 12) / 12;
    double y = (M_PI + 6 * sqrt(3) - 12) / 3;
    double z = (12 - 2 * M_PI - 3 * sqrt(3)) / 3;
    // cout << x + y + z << endl;
    while(cin.peek() != EOF) {
        double a;
        cin >> a;
        cout << setprecision(3) << setiosflags(ios::fixed) << double(round(1000 * (a * a * x)) / 1000) << " ";
        cout << setprecision(3) << setiosflags(ios::fixed) << double(round(1000 * (a * a * y)) / 1000) << " ";
        cout << setprecision(3) << setiosflags(ios::fixed) << double(round(1000 * (a * a * z)) / 1000) << endl;
        // cout << setprecision(3) << setiosflags(ios::fixed) << setiosflags(ios::showpoint) << 1 << " ";
    }
}