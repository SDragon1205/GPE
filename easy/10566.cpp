#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	float x1, x2, x3, x4, y1, y2, y3, y4;
	while(scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) == 8)
	{
		if(x1 == x3 && y1 == y3)
		{
			printf("%.3f %.3f\n", x2+x4-x1, y2+y4-y1);
		}
		else if(x1 == x4 && y1 == y4)
		{
			printf("%.3f %.3f\n", x2+x3-x1, y2+y3-y1);
		}
		else if(x2 == x3 && y2 == y3)
		{
			printf("%.3f %.3f\n", x1+x4-x2, y1+y4-y2);
		}
		else // 2 == 4
		{
			printf("%.3f %.3f\n", x1+x3-x2, y1+y3-y2);
		}
	}
}
