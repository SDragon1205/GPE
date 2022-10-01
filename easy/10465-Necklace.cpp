#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>

using namespace std;

int main()
{
	double vt, v0, v, d, max, ans;
	char s1[100], s2[100];
	cin >> vt >> v0;
	while(vt || v0)
	{
		max = 0;
		ans = 0;
		for(double i = 1; i < vt; i++)
		{
			v = vt / i;
			if(v < v0)
			{
				break;
			}
			else
			{
				d = 0.3*sqrt(v - v0)*i;
			}
			
			sprintf(s1, "%.10lf", d);
			sprintf(s2, "%.10lf", max);
			//cout << "d: " << s1 << ", max: " << s2 << ", cmp: " << strcmp(s1, s2) << "\n";
			
			if(strcmp(s1, s2) == 0)
			{
				ans = 0;
			}
			else if(d > max)
			{
				ans = i;
				max = d;
			}
		}
		
		cout << ans << "\n";
		cin >> vt >> v0; 
	}
 } 
 
 //https://mypaper.pchome.com.tw/zerojudge/post/1322861011
