#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

struct point{
    double x, y;
}p[100];

int n;
double a, b;
pair <double,double> foo;

int main()
{
    int cases;
    cin >> cases;
    for(int ca = 0; ca < cases; ca++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y;
        }
        map<pair<double, double>, int> line;
        map<double, int> line2;
        int ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            for(int  j= i+1; j < n; j++)
            {
                if(p[i].x-p[j].x)
                {
                    a = (p[i].y - p[j].y)/(p[i].x - p[j].x);
                    b = ((p[j].x*p[i].y)-(p[i].x*p[j].y))/(p[j].x - p[i].x);
                    foo = make_pair(a, b);
                    if(line.find(foo) == line.end())
                    {
                        ans++;
                        line[foo] = 1;
                    }
                }
                else
                {
                    if(line2.find(p[i].x) == line2.end())
                    {
                        ans++;
                        line2[p[i].x] = 1;
                    }
                    
                }
            }
        }

        cout << ans << "\n";
    }
}