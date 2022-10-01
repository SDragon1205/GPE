#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int which_layer(int w) {
    int i;
    int sum = 0;
    for(i = 0; true; i++) {
        sum += i * 6;
        if(w <= sum + 1) {
            break;
        }
    }
    return i;
}

int std_position(int w) {
    int layer = which_layer(w);
    return ((layer + 1) * layer / 2) * 6 + 1;
}

int rev_order(int w) {
    return std_position(w) - w;
}

int which_side(int w) {
    if(w == 1) {
        return 0;
    }
    return rev_order(w) / which_layer(w);
}

int rev_order_in_side(int w) {
    if(w == 1) {
        return 0;
    }
    return (std_position(w) - w) % which_layer(w);
}

int main(void) {
    int i = 0;
    while(cin.peek() != EOF) {
        if(i) {
            cout << endl;
        }
        int w;
        cin >> w;
        int layer = which_layer(w);
        int rev = rev_order(w);
        int side = which_side(w);
        int revInSide = rev_order_in_side(w);
        int x = layer;
        int y = 0;
        // cout << ":" << rev_order_in_side(w) << endl;
        if(side == 0) {
            x = layer;
            y = 0 - revInSide;
        } else if(side == 1) {
            x = layer - revInSide;
            y = -layer;
        } else if(side == 2) {
            x = 0 - revInSide;
            y = -layer + revInSide;
        } else if(side == 3) {
            x = -layer;
            y = 0 + revInSide;
        } else if(side == 4) {
            x = -layer + revInSide;
            y = layer;
        } else {
            x = 0 + revInSide;
            y = layer - revInSide;
        }
        cout << x << " " << y;
        i++;
    }
    return 0;
} 