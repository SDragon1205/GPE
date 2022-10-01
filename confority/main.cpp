#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

int main(void) {
    while(true) {
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        map<set<int>, int> combinations;
        for(int f = 0; f < n; f++) {
            set<int> combination;
            for(int c = 0; c < 5; c++) {
                int courseNum;
                cin >> courseNum;
                combination.insert(courseNum);
            }
            if(combinations.find(combination) == combinations.end()) {
                combinations[combination] = 1;
            } else {
                combinations[combination] += 1;
            }
        }
        map<int, vector<set<int> > > popRank;
        map<set<int>, int>::iterator iter;
        int mostPopRank = 0;
        for(iter = combinations.begin(); iter != combinations.end(); iter++) {
            if(popRank.find(iter->second) == popRank.end()) {
                vector<set<int> > sets;
                sets.push_back(iter->first);
                popRank[iter->second] = sets;
            } else {
                popRank[iter->second].push_back(iter->first);
            }
            if(iter->second > mostPopRank) {
                mostPopRank = iter->second;
            }
        }
        int studentsNum = 0;
        for(int i = 0; i < popRank[mostPopRank].size(); i++) {
            studentsNum += combinations[popRank[mostPopRank][i]];
        }
        cout << studentsNum << endl;
    }
    return 0;
}