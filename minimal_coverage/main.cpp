#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct tuple{
    int l;
    int r;
};

bool compare(tuple a, tuple b) {
    if(a.l < b.l) {
        return true;
    } else if(a.l == b.l) {
        if(a.r <= b.r) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    return a.l < b.l;
}

int main(void) {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<tuple> tupleArr;
        while(true) {
            int l, r;
            cin >> l >> r;
            if(l == 0 && r == 0) {
                break;
            }
            if(r > 0 && l < m) {
                tuple temp;
                temp.l = l;
                temp.r = r;
                tupleArr.push_back(temp);
            }
        }
        sort(tupleArr.begin(), tupleArr.end(), compare);
        // cout << "=====================" << endl;
        // for(int j = 0; j < tupleArr.size(); j++) {
        //     cout << tupleArr[j].l << " " << tupleArr[j].r << endl;
        // }
        // cout << "=====================" << endl;
        vector<tuple> result;
        vector<tuple>::iterator iter;
        int rangel = 0, ranger = 0, maxExpand = 0;
        tuple maxExpandTuple;
        if(tupleArr.size() > 0) {
            maxExpandTuple.l = tupleArr[0].l;
            maxExpandTuple.r = tupleArr[0].r;
        }
        for(iter = tupleArr.begin(); iter != tupleArr.end(); iter++) {
            if(iter->l > ranger || iter == tupleArr.end() - 1) {
                rangel = ranger;
                ranger += maxExpand;
                maxExpand = 0;
                // cout << "add : (" << maxExpandTuple.l << ", " << maxExpandTuple.r << ")" << endl;
                result.push_back(maxExpandTuple);
            } else {
                if(iter->r - ranger >= maxExpand) {
                    maxExpand = iter->r - ranger;
                    maxExpandTuple.l = iter->l;
                    maxExpandTuple.r = iter->r;
                }
            }
        }
        cout << result.size() << endl;
        if(result.size() != 0) {
            for(iter = result.begin(); iter != result.end(); iter++) {
                cout << iter->l << " " << iter->r << endl;
            }
        }
        cout << endl;
    }
}