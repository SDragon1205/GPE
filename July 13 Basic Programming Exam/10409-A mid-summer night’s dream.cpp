#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int mid1, mid2;
    int ans1, ans2, ans3;
    while(cin >> n)
    {
        int x[n];
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        sort(x, x+n);

        mid2 = x[n/2];
        ans2 = 0;
        if(n%2)
        {
            ans1 = mid2;
            ans3 = 1;
            for(int i = 0; i < n; i++)
            {
                if(x[i] == mid2)
                {
                    ans2++;
                }
            }
        }
        else
        {
            mid1 = x[(n/2)-1];
            ans1 = mid1;
            ans3 = mid2 - mid1 + 1;
            for(int i = 0; i < n; i++)
            {
                if(mid1 == x[i] || x[i] == mid2)
                {
                    ans2++;
                }
            }
        }

        printf("%d %d %d\n", ans1, ans2, ans3);
    }
}