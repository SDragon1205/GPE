#include <iostream>
#include <cstdlib>
#include <cstdio>

#define SIZE 100000

using namespace std;

struct point {
    int x;
    int y;
};

point p[SIZE + 1];

void create() {
    int i = 1;
    int layer = 0;
    int curx = 0;
    int cury = 0;
    p[1].x = curx;
    p[1].y = cury;
    for(; i <= SIZE; layer++) {
        // cout << "===========(1)==========\n";
        for(int j = 1; j < layer && i <= SIZE; j++) {
            // cout << i << endl;
            p[i].x = curx;
            p[i].y = cury;
            i++;
            curx -= 1;
            cury += 1;
        }
        // cout << "===========(2)==========\n";
        for(int j = 0; j < layer && i <= SIZE; j++) {
            // cout << i << endl;
            p[i].x = curx;
            p[i].y = cury;
            i++;
            curx -= 1;
        }
        // cout << "===========(3)==========\n";
        for(int j = 0; j < layer && i <= SIZE; j++) {
            // cout << i << endl;
            p[i].x = curx;
            p[i].y = cury;
            i++;
            cury -= 1;
        }
        // cout << "===========(4)==========\n";
        for(int j = 0; j < layer && i <= SIZE; j++) {
            // cout << i << endl;
            p[i].x = curx;
            p[i].y = cury;
            i++;
            curx += 1;
            cury -= 1;
        }
        // cout << "===========(5)==========\n";
        for(int j = 0; j < layer && i <= SIZE; j++) {
            // cout << i << endl;
            p[i].x = curx;
            p[i].y = cury;
            i++;
            curx += 1;
        }
        // cout << "===========(6)==========\n";
        for(int j = 0; j <= layer && i <= SIZE; j++) {
            // cout << i << endl;
            p[i].x = curx;
            p[i].y = cury;
            i++;
            cury += 1;
        }
    }
}

int main(void) {
    create();
    // for(int i = 1; i <= SIZE; i++) {
    //     cout << i << " : ";
    //     cout << p[i].x << " " << p[i].y << endl;
    // }
    while(cin.peek() != EOF) {
        int w;
        cin >> w;
        cout << p[w].x << " " << p[w].y << endl;
    }
}