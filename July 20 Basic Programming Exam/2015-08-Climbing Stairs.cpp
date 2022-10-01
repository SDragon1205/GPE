#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    unsigned long long int ans[101];
    unsigned long long int n;
    cin >> n;
    ans[1] = 1;
    ans[2] = 2;
    for(int i = 3; i <= n; i++)
    {
        ans[i] = ans[i-1]+ans[i-2];
    }

    // for(int i = 1; i <= twon; i++)
    // {
    //     n--;
    //     now = 1;
    //     for(unsigned long long int j = n; j > n - i; j--)
    //     {
    //         now *= j;
    //     }
    //     for(unsigned long long int j = 2; j <= i; j++)
    //     {
    //         now /= j;
    //     }
    //     //cout << "now: " << now << "\n";
    //     ans += now;
    // }

    cout << ans[n] << "\n";
}