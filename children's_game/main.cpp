#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

int main(void) {
    while(true) {
        int n;
        if(n == 0) {
            break;
        }
        int num[n];
        string str[n];
        for(int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            str[i] = to_string(temp);
        }
    }
}