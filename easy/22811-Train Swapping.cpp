#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int l;
        scanf("%d", &l);
        int c[l];
        for(int j = 0; j < l; j++)
        {
            scanf("%d", &c[j]);
        }

        int ans = 0;
        int s;
        for(int a = l-1; a > 0; a--)
        {
            for(int b = 0; b < a; b++)
            {
                if(c[b] > c[b+1])
                {
                    s = c[b];
                    c[b] = c[b+1];
                    c[b+1] = s;
                    ans++;
                }
            }
        }

        printf("Optimal train swapping takes %d swaps.\n", ans);
    }
}

//http://naivered.github.io/2016/05/26/Problem_Solving/UVa/UVa-10020-Minimal-coverage/
