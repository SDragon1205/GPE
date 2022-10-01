#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

int main(void) {
    while(true) {
        long int n;
        cin >> n;
        if(!n) {
            break;
        }
        long int c1, n1, c2, n2, x1 = -1, x2 = -1;
        cin >> c1 >> n1 >> c2 >> n2;
        if(n1 * c2 > n2 * c1) {
            for(long int i = 0; i <= n / n2; i++) {
                if((n - i * n2) % n1 == 0) {
                    x1 = (n - i * n2) / n1;
                    x2 = i;
                    break;
                }
            }
        } else {
            for(long int i = 0; i <= n / n1; i++) {
                if((n - i * n1) % n2 == 0) {
                    x1 = i;
                    x2 = (n - i * n1) / n2;
                    break;
                }
            }
        }
        if(x1 >= 0) {
            cout << x1 << " " << x2 << endl;
        } else {
            cout << "failed" << endl;
        }
    }
    return 0;
}