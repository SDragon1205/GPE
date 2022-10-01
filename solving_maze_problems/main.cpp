#include <iostream>
#include <cstdlib>
#include <queue>
#include <utility>

using namespace std;

int main(void) {
    char m[10][10];
    bool visitedMap[10][10];
    pair<int, int> parentMap[10][10];
    int si, sj, gi, gj;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> m[i][j];
            visitedMap[i][j] = false;
            if(m[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if(m[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }
    // cout << "=========" << endl;
    // cout << si << " " << sj << endl;
    // cout << gi << " " << gj << endl;
    // cout << "=========" << endl;
    queue<pair<int, int> > searchingEdge;
    searchingEdge.push(pair<int, int>(si, sj));
    while(true) {
        pair<int, int> searching = searchingEdge.front();
        // cout << searching.first << " " << searching.second << endl;
        searchingEdge.pop();
        if(searching.first == gi && searching.second == gj) {
            break;
        }
        int surrounding[4][2] = {{searching.first - 1, searching.second},
                                 {searching.first, searching.second + 1},
                                 {searching.first + 1, searching.second},
                                 {searching.first, searching.second - 1}};
        for(int k = 0; k < 4; k++) {
            int checkingi = surrounding[k][0];
            int checkingj = surrounding[k][1];
            if(checkingi >= 0 && checkingi < 10) {
                if(checkingj >= 0 && checkingj < 10) {
                    if(m[checkingi][checkingj] != '#' && !visitedMap[checkingi][checkingj]) {
                        searchingEdge.push(pair<int, int>(checkingi, checkingj));
                        parentMap[checkingi][checkingj] = searching;
                        visitedMap[checkingi][checkingj] = true;
                    }
                }
            }
        }
        if(searchingEdge.empty()) {
            cout << "No solution" << endl;
            return 0;
        }
    }
    // cout << "find!!" << endl;
    int curi = gi, curj = gj;
    m[gi][gj] = '+';
    m[si][sj] = '+';
    while(true) {
        int temp = curi;
        curi = parentMap[curi][curj].first;
        curj = parentMap[temp][curj].second;
        if(curi == si && curj == sj) {
            break;
        }
        m[curi][curj] = '+';
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
    return 0;
}