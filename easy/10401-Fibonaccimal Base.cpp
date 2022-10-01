#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int main()
{
    vector<int> fi;
    fi.push_back(0);
    fi.push_back(1);
    for(int i = 2; fi[i-1] < 100000000; i++)
    {
        //cout << "fi: " << fi[i-2] + fi[i-1] << "\n";
        fi.push_back(fi[i-2] + fi[i-1]);
    }


    int n, a, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        printf("%d = ", a);

        x = fi.size()-1;
        while(fi[x] > a)
        {
            x--;
        }
        //cout << "x: " << x << "\n";

        bool ch = false;
        while(x > 1)
        {
            if(ch)
            {
                printf("0");
                ch = false;
            }
            else if(fi[x] <= a)
            {
                a -= fi[x];
                printf("1");
                ch = true;
            }
            else
            {
                printf("0");
            }
            x--;
        }

        printf(" (fib)\n");
    }
}

//https://mypaper.pchome.com.tw/zerojudge/post/1322223788