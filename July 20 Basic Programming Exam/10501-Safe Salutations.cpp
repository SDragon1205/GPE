#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int p[10];

int main()
{
    p[0] = 1;
    p[1] = 1;
    vector<int> ans;
    for(int i = 2; i <= 10; i++)
    {
        for(int j = 0; j <= i-1; j++)
        {
            p[i] += p[j] * p[i-j-1];
        }
    }

    int n;
    int f = 0;
    while(cin >> n)
    {
        if(f)
        {
            cout << "\n";
        }
        cout << p[n] << "\n";
        f = 1;
    }
}