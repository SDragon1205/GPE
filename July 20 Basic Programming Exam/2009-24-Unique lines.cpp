#include <iostream>
#include <cstdio>
#include <map>
#include <utility>

using namespace std;

struct point
{
    double x;
    double y;
}p[100];

int main()
{
    double cases, num, ans;
    double a, b;
    pair <double, double> foo;

    cin >> cases;
    for(int ca = 0; ca < cases; ca++)
    {
        map<pair<double, double> ,int> line;
        map<double, double> line2;
        cin >> num;
        for(int i = 0; i < num; i++)
        {
            cin >> p[i].x >> p[i].y;
        }

        ans = 0;
        for(int i = 0; i < num-1; i++)
        {
            for(int j = i+1; j < num; j++)
            {
                if(p[i].x != p[j].x)
                {
                    a = (p[i].y-p[j].y)/(p[i].x-p[j].x);
                    //cout << "a: " << a << "\n";
                    b = (p[i].y*p[j].x - p[i].x*p[j].y) / (p[j].x - p[i].x);
                    //cout << "b: " << b << "\n";

                    foo = make_pair(a, b);
                    if(line.find(foo) == line.end())
                    {
                        line[foo] = 1;
                        ans++;
                        //cout << "ans: " << ans << "\n";
                    }
                }
                else
                {
                    a = p[i].x;
                    if(line2.find(a) == line2.end())
                    {
                        line2[a] = 1;
                        ans++;
                        //cout << "c: " << a << "\n";
                        //cout << "ans: " << ans << "\n";
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}