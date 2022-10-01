#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main(void) {
    while(cin.peek() != EOF) {
        string str1, str2;
        cin >> str1;
        cin >> str2;
        int l1 = str1.length();
        int l2 = str2.length();
        short dynamicArr[l1 + 1][l2 + 1];
        for(int i = 0; i <= l1; i++) {
            dynamicArr[i][0] = 0;
        }
        for(int i = 0; i <= l2; i++) {
            dynamicArr[0][i] = 0;
        }
        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(str1[i - 1] == str2[j - 1]) {
                    dynamicArr[i][j] = dynamicArr[i - 1][j - 1] + 1;
                } else {
                    if(dynamicArr[i - 1][j] > dynamicArr[i][j - 1]) {
                        dynamicArr[i][j] = dynamicArr[i - 1][j];
                    } else {
                        dynamicArr[i][j] = dynamicArr[i][j - 1];
                    }
                }
            }
        }
        cout << dynamicArr[l1][l2] << endl;
    }
}