#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

// set<int> reducibleNumbers;

// void chainMultiple(set<int> factors, int base, int n) {
//     for(set<int>::iterator iter = factors.begin(); iter != factors.end(); iter++) {
//         int newBase = base * (*iter);
//         if(newBase <= n) {
//             reducibleNumbers.insert(newBase);
//             chainMultiple(factors, newBase, n);
//         }
//     }
// }

// int countMultiple(set<int> factors, int n) {
//     reducibleNumbers.clear();
//     chainMultiple(factors, 1, n);
//     cout << "===" << endl;
//     for(set<int>::iterator iter = reducibleNumbers.begin(); iter != reducibleNumbers.end(); iter++) {
//         cout << "->" << *iter << endl;
//     }
//     cout << reducibleNumbers.size() << endl;
//     return reducibleNumbers.size();
// }

int main(void) {
    while(true) {
        int n = -1;
        cin >> n;
        if(n == 0) {
            break;
        }
        set<int> factors;
        int rawn = n;
        while(n > 1) {
            int i;
            bool hit = false;
            // cout << "n = " << n << endl;
            for(i = 2; i <= sqrt(n) + 1; i++) {
                if(n % i == 0) { 
                    hit = true;
                    break;
                }
            }
            if(!hit) {
                i = n;
            }
            n = n / i;
            factors.insert(i);
            // cout << i << endl;
        }
        // for(set<int>::iterator iter = factors.begin(); iter != factors.end(); iter++) {
        //     cout << *iter << endl;
        // }
        int ans = 0;
        set<int> reducibleNumbers;
        for(set<int>::iterator iter = factors.begin(); iter != factors.end(); iter++) {
            for(int i = 1; i <= rawn / (*iter); i++) {
                reducibleNumbers.insert(*iter * i);
            }
        }
        // int ans = rawn - countMultiple(factors, rawn);
        ans = rawn - reducibleNumbers.size();
        cout << ans << endl;
    }
}