#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>
#include <set>

using namespace std;

set<int> reducibleNumbers;

void chainMultiple(set<int> factors, int base, int n) {
    for(set<int>::iterator iter = factors.begin(); iter != factors.end(); iter++) {
        int newBase = base * (*iter);
        if(newBase <= n) {
            reducibleNumbers.insert(newBase);
            chainMultiple(factors, newBase, n);
        }
    }
}

int countMultiple(set<int> factors, int n) {
    reducibleNumbers.clear();
    chainMultiple(factors, 1, n);
    cout << "===" << endl;
    for(set<int>::iterator iter = reducibleNumbers.begin(); iter != reducibleNumbers.end(); iter++) {
        cout << "->" << *iter << endl;
    }
    cout << reducibleNumbers.size() << endl;
    return reducibleNumbers.size();
}

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
            for(i = 2; i <= n / 2 + 1; i++) {
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
        for(set<int>::iterator iter = factors.begin(); iter != factors.end(); iter++) {
            cout << *iter << endl;
        }
        int ans = rawn - countMultiple(factors, rawn);
        cout << ans << endl;
    }
}