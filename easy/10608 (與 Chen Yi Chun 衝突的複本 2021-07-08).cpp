#include <iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>

using namespace std;

struct seg{
    int l;
    int r;
};

bool comp(seg a, seg b)
{
    return a.l < b.l;
}

int main()
{
    int m, c;
    scanf("%d", &c);
    for(int ca = c-1; ca >= 0; ca--)
    {
        cin.ignore();
        cin.ignore();
        scanf("%d", &m);
        vector<seg> s;
        vector<int> ansind;
        seg in;
        while(scanf("%d %d", &in.l, &in.r) && (in.l || in.r))
        {
        	//cout << "ch: " << in.l << " " << in.r << "\n";
            s.push_back(in);
        }
        sort(s.begin(), s.end(), comp);
        
        int now = 0;
        for(int i = 0; i < s.size();)
        {
        	if(now >= m || s[i].l > now)
        	{
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

            if(max <= now)
            {
                break;
            }

            ansind.push_back(ind);
            now = max;
        }

        if(now >= m)
        {
            printf("%d\n", ansind.size());
            for(int j = 0; j < ansind.size(); j++)
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
