#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

int GCD(int a, int b) {
    if(a % b) {
        return(b, a % b);
    } else {
        return b;
    }
}

int LCM(int a, int b) {
    if(a > b) {
        return(a * b / GCD(a, b));
    } else {
        return(a * b / GCD(b, a));
    }
}

int main(void) {
    while(true) {
        int n;
        cin >> n;
        if(!n) {
            break;
        }
        int c1, n1, c2, n2;
        cin >> c1 >> n1 >> c2 >> n2;
        vector<pair<int, int> > combinations;
        for(int i = 0; i < n / n1; i++) {
            if((n - i * n1) % n2 == 0) {
                combinations.push_back(pair<int, int>(i, (n - i * n1) / n2));
                break;
            }
        }
        if(combinations.size()) {
            int lcm = LCM(n1, n2);
            int steps1 = lcm / n1;
            int steps2 = lcm / n2;
            for(int i = 0; combinations[0].second - i * steps2 > 0; i++) {
                combinations.push_back(pair<int, int>(
                    combinations[0].first + steps1,
                    combinations[0].second - steps2)
                );
            }
        } else {
            cout << "failed" << endl;
        }
    }
    return 0;
}