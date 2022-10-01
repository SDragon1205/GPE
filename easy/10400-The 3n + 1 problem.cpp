#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int i, j, m, c, mi, ma, a, n;
    //while(scanf("%d %d", &i, &j) == 2)
    while(cin >> i >> j)
    {
        //cout << i << " " << j << "\n";
        m = 0;
        if(i < j)
        {
            mi = i;
            ma = j;
        }
        else
        {
            mi = j;
            ma = i;
        }

        for(a = mi; a <= ma; a++)
        {
            n = a;
            c = 0;
            //cout << "n: " << n << "\n";
            while(n != 1)
            {
                c++;
                if(n % 2 == 1)
                {
                    n = 3*n + 1;
                }
                else
                {
                    n /= 2;
                }
            }

            if(c > m)
            {
                m = c;
            }
        }

        //printf("%d %d %d\n", i, j, ++m);
        cout << i << " " << j << " " << ++m << "\n";
    }
}
