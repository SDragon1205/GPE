#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int GCD(int a, int b) {
    if(b > 1) {
        return(GCD(b, a % b));
    } else if(b == 0) {
        return(a);
    } else {
        return(1);
    }
}

int main(void) {
    while(true) {
        int n = -1;
        cin >> n;
        if(n == 0) {
            break;
        }
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(GCD(n, i) == 1) {
                ans += 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}