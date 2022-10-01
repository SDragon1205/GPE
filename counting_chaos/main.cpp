#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdio>

using namespace std;

int main(void) {
    string time[1440];
    string lastPalindromicTime = "";
    for(int i = 1439; i >= 0; i--) {
        time[i] = lastPalindromicTime;
        int h = i / 60;
        int m = i % 60;
        string hh, mm;
        stringstream ss;
        ss.str("");
        ss.clear();
        ss << h;
        hh = ss.str();
        ss.str("");
        ss.clear();
        ss << m;
        mm = ss.str();
        // cout << hh << ' ' << mm << endl;
        if(hh.length() == 1) {
            hh = '0' + hh;
        }
        if(mm.length() == 1) {
            mm = '0' + mm;
        }
        string timeFormat = hh + mm;
        int firstNoneZero;
        for(firstNoneZero = 0; firstNoneZero < 4; firstNoneZero++) {
            if(timeFormat[firstNoneZero] != '0') {
                break;
            }
        }
        string temp = timeFormat.substr(firstNoneZero, 4 - firstNoneZero);
        // cout << timeFormat << endl;
        if(temp.length() == 4) {
            if(temp[0] == temp[3] && temp[1] == temp[2]) {
                lastPalindromicTime = timeFormat;
            }
        } else if(temp.length() == 3) {
            if(temp[0] == temp[2]) {
                lastPalindromicTime = timeFormat;
            }
        } else if(temp.length() == 2) {
            if(temp[0] == temp[1]) {
                lastPalindromicTime = timeFormat;
            }
        } else {
            lastPalindromicTime = timeFormat;
        }
    }
    for(int i = 1439; i >= 0; i--) {
        if(time[i] == "") {
            time[i] = lastPalindromicTime;
        } else {
            break;
        }
    }
    // for(int i = 0; i < 1440; i++) {
    //     cout << setw(2) << setfill('0') << i / 60 << ":";
    //     cout << setw(2) << setfill('0') << i % 60 << " = ";
    //     cout << time[i] << endl;
    // }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        cout << time[atoi(temp.substr(0, 2).c_str()) * 60 + atoi(temp.substr(3, 2).c_str())].substr(0, 2);
        cout << ':';
        cout << time[atoi(temp.substr(0, 2).c_str()) * 60 + atoi(temp.substr(3, 2).c_str())].substr(2, 2);
        cout << endl;
    }
}
