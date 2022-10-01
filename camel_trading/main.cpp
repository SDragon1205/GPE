#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    cin.get();
    for(int i = 0; i < n; i++) {
        int tempNum = 0;

        int tempSum = 0;
        int Mans = 1;

        int tempPro = 1;
        int mans = 0;
        while(true) {
            char ch = cin.get();
            if(ch == '\n' || ch == EOF) {
                tempSum += tempNum;
                Mans *= tempSum;

                tempPro *= tempNum;
                mans += tempPro;

                tempNum = 0;
                break;
            }
            if(ch == '+') {
                tempSum += tempNum;

                tempPro *= tempNum;
                mans += tempPro;
                tempPro = 1;

                tempNum = 0;
            } else if(ch == '*') {
                tempSum += tempNum;
                Mans *= tempSum;
                tempSum = 0;

                tempPro *= tempNum;

                tempNum = 0;
            } else {
                tempNum = tempNum * 10 + (ch - 48);
                // cout << tempNum << "," << endl;
            }
        }
        cout << "The maximum and minimum are " << Mans << " and " << mans << "." << endl;
    }
    return 0;
}