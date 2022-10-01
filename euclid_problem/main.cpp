#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct num4GCD
{
    int aNum;
    int bNum;
    int num;
};

void GCD(num4GCD a, num4GCD b) {
    num4GCD newa, newb;
    // cout << "A : " << a.aNum << ", " << a.bNum << ", " << a.num << endl;
    // cout << "B : " << b.aNum << ", " << b.bNum << ", " << b.num << endl;
    if(a.num % b.num != 0) {
        newa.aNum = a.aNum - b.aNum * (a.num / b.num);
        newa.bNum = a.bNum - b.bNum * (a.num / b.num);
        newa.num = a.num % b.num;
        newb = b;
        GCD(newb, newa);
    } else {
        // cout << "=======================" << endl;
        // cout << "B : " << b.aNum << ", " << b.bNum << ", " << b.num << endl;
        // newb = b;
        // cout << "B : " << newb.aNum << ", " << newb.bNum << ", " << newb.num << endl;
        // return newb;
        // if(b.bNum < b.aNum) {
        //     cout << b.bNum << " " << b.aNum << " " << b.num << endl;
        // } else {
        //     cout << b.aNum << " " << b.bNum << " " << b.num << endl;
        // }
        cout << b.aNum << " " << b.bNum << " " << b.num << endl;
        return;
    }
}

int main(void) {
    while(true) {
        char ch = cin.peek();
        if(ch == EOF) {
            break;
        }
        int A, B;
        cin >> A >> B;
        num4GCD a;
        a.aNum = 1;
        a.bNum = 0;
        a.num = A;
        num4GCD b;
        b.aNum = 0;
        b.bNum = 1;
        b.num = B;
        // num4GCD result;
        if(A < B) {
            GCD(b, a);
        } else {
            GCD(a, b);
        }
    }
    return 0;
}