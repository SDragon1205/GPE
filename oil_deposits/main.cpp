#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
int offset[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int main(void) {
    while(true) {
        int m, n;
        cin >> m >> n;
        if(m == 0) {
            break;
        }
        char oilmap[m][n];
        bool b_oilmap[m][n];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> oilmap[i][j];
                b_oilmap[i][j] = false;
            }
        }
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << oilmap[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        int depositNum = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(oilmap[i][j] == '@' && b_oilmap[i][j] == false) {
                    queue<pair<int, int> > q;
                    q.push(make_pair(i, j));
                    while(!q.empty()) {
                        pair<int, int>pos = q.front();
                        q.pop();
                        // cout << "front : " << '(' << pos.first << ", " << pos.second << ')' << endl;
                        b_oilmap[pos.first][pos.second] = true;
                        vector<pair<int, int> > surr_q;
                        for(int k = 0; k < 8; k++) {
                            int row = pos.first + offset[k][0];
                            int column = pos.second + offset[k][1];
                            if((row > -1 && row < m) && (column > -1 && column < n)) {
                                surr_q.push_back(make_pair(row, column));
                            }
                        }
                        // cout << "=========" << endl;
                        for(int k = 0; k < surr_q.size(); k++) {
                            int row = surr_q[k].first;
                            int column = surr_q[k].second;
                            if(oilmap[row][column] == '@' && b_oilmap[row][column] == false) {
                                // cout << '(' << row << ", " << column << ')' << endl;
                                q.push(make_pair(row, column));
                            }
                        }
                        // cout << "=========" << endl;
                    }
                    depositNum += 1;
                }
            }
        }
        cout << depositNum << endl;
    }
}