#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <iomanip>
#include <climits>

using namespace std;

int main(void) {
    while(true) {
        int L;
        cin >> L;
        if(!L) {
            break;
        }
        int c;
        cin >> c;
        int cuttingPositions[c];
        int partLength[c + 1];
        int joinLenthTable[c + 1][c + 1];
        int costTable[c + 1][c + 1];
        // int cuttingPositionTable[c][c];
        for(int i = 0; i < c; i++) {
            cin >> cuttingPositions[i];
        }
        int lastLength = L;
        for(int i = c; i > 0; i--) {
            partLength[i] = lastLength - cuttingPositions[i - 1];
            lastLength = cuttingPositions[i - 1];
        }
        partLength[0] = lastLength;
        int joinLength = 0;
        for(int i = 0; i <= c; i++) {
            joinLength = 0;
            for(int j = c - i; j >= 0; j--) {
                joinLength += partLength[j];
                joinLenthTable[i][j] = joinLength;
                costTable[i][j] = 0;
            }
        }
        for(int i = c - 1; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                int minCostAdd = INT_MAX;
                // int minCuttingPosition = INT_MAX;
                for(int k = i - j + 1; k <= c - j; k++) {
                    if(costTable[j][k] + costTable[c + 1 - k][i - j] < minCostAdd) {
                        minCostAdd = costTable[j][k] + costTable[c + 1 - k][i - j];
                    }
                }
                costTable[j][i - j] = joinLenthTable[j][i - j] + minCostAdd;
            }
        }
        // for(int i = 0; i <= c; i++) {
        //     for(int j = 0; j <= c - i; j++) {
        //         cout << setw(3) << setfill(' ') << joinLenthTable[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // for(int i = 0; i <= c; i++) {
        //     for(int j = 0; j <= c - i; j++) {
        //         cout << setw(3) << setfill(' ') << costTable[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << "The minimum cutting is " << costTable[0][0] << "." << endl;
    }
    return 0;
}