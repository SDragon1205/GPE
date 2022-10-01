#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(void) {
    for(int caseN = 1; true; caseN++) {
        string str = "";
        char ch;
        int len = 0;
        while(true) {
            char ch = getchar();
            if(ch == '0' || ch == '1') {
                str += ch;
                len += 1;
            } else {
                break;
            }
        }
        if(ch == EOF || len == 0) {
            break;
        }
        cout << "Case " << caseN << ":\n";
        int n;
        cin >> n;
        //cout << n << endl;
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if(b < a) {
                int temp = b;
                b = a;
                a = temp;
            }
            char first = str[a];
            int idx = a + 1;
            for(idx = a + 1; idx <= b; idx++) {
                if(str[idx] != first) {
                    break;
                }
            }
            if(idx != b + 1) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
        getchar();
    }
}