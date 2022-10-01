#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct seg{
    int l;
    int r;
};

bool comp(seg a, seg b)
{
    if(a.l < b.l)
    {
        return true;
    }
    return false;
}

int main()
{
    int m;
    scanf("%d", &m);
    for(int ca = m-1; ca >= 0; ca--)
    {
        cin.ignore();
        cin.ignore();
        vector<seg> s;
        vector<int> ansind;
        seg in;
        while(scanf("%d %d", &in.l, in.r) && (in.l || in.r))
        {
            s.push_back(in);
        }
        
        int ans = 0;
        int now = 0;
        for(int i = 0; i < s.size(); ans++)
        {
            if(s[i].l > m)
            {
                ans = 0;
                break;
            }
            int max = s[i].r;
            int ind = i;
            while(s[i].l <= now && i < s.size())
            {
                if(s[i].r > max)
                {
                    max = s[i].r;
                    ind = i;
                }
                i++;
            }

            if(max < now)
            {
                ans = 0;
                break;
            }

            ansind.push_back(ind);
            now = max;
        }

        if(ans)
        {
            printf("%d\n", ans);
            for(int j = 0; j < ans; j++)
            {
                printf("%d %d\n", s[ansind[j]].l, s[ansind[j]].r);
            }
        }
        else
        {
            printf("0\n");
        }

        if(ca)
        {
            printf("\n");
        }
    }
}