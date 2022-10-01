#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>

using namespace std;

struct point
{
	float x, y;
}p[100];

float cross(point a, point b)
{
	return fabs((a.x*b.y)-(a.y*b.x));
}

int main()
{
	int a;
	
	cin >> a;
	while(a >= 3)
	{
		float aa, x, y, w;
		x = 0;
		y = 0;
		w = 0;
		for(int i = 0; i < a; i++)
		{
			cin >> p[i].x;
			cin >> p[i].y;
		}
		for(int j = 1; j < a; j++)
		{
			int i = j-1;
			aa = cross(p[i], p[j]);
			x += (p[i].x+p[j].x)*aa;
			//cout << 
			y += (p[i].y+p[j].y)*aa;
			w += aa;
		}
		aa = cross(p[0], p[a-1]);
		x += (p[0].x+p[a-1].x)*aa;
		y += (p[0].y+p[a-1].y)*aa;
		w += aa;
		
		
		cout << setiosflags(ios::fixed) << setprecision(3) << (x/3)/w << " ";
		cout << setiosflags(ios::fixed) << setprecision(3) << (y/3)/w << "\n";
		
		
		cin >> a;
	}
	
	return 0;
}
