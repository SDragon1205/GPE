#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
	int n, i, c, max;
	cin >> n;
	while(n)
	{
		cout << n << " : ";
		
		c = 0;
		max = (int)sqrt(n);
		for(i = 2; i <= max; i++)
		{
			if(n % i == 0)
			{
				c++;
				while(n % i == 0)
				{
					n /= i;
				}
			}	
		}
		
		if(n > 1)
		{
			c++;
		}
		cout << c << "\n";
		
		cin >> n;
	}
 } 
