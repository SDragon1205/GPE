#include<iostream>
#include<cstdio>

using namespace std;

int turn(string a)
{
    int ans = 0;
    for(int i = 0; i < a.size(); i++)
    {
        ans *= 2;
        if(a[i] == '1')
        {
            ans ++;
        }
    }

    return ans;
}

int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    return gcd(b, a%b);
}

int main()
{
    int n, g;
    string ss1, ss2;
    scanf("%d", &n);
    for(int in = 1; in <= n; in++)
    {
        cin >> ss1 >> ss2;
        int s1 = turn(ss1);
        int s2 = turn(ss2);
        //cout << "s1: " << s1 << "\n";
        //cout << "s2: " << s2 << "\n";
        if(s1 < s2)
        {
            int c = s1;
            s1 = s2;
            s2 = c;
        }
        g = gcd(s1, s2);

        if(g == 1)
        {
            printf("Pair #%d: Love is not all you need!\n", in);
        }
        else
        {
            printf("Pair #%d: All you need is love!\n", in);
        }
    }
}