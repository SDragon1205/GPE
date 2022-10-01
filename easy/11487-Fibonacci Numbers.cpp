#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		if(n == 1 | n == 2)
		{
			cout << "1\n";
		}
		else
		{
			int a[1000] = {0}, b[1000] = {0}, f[1000] = {0};
			a[0] = 1;
			b[0] = 1;
			int len = 1;
			int carry;
			for(int i = 3; i <= n; i++)
			{
				carry = 0;
				for(int j = 0; j < len; j++)
				{
					carry = a[j] + b[j] + carry;
					f[j] = carry % 10;
					carry /= 10;
				}
				
				//cout << "carry: " << carry << "\n";
				if(carry)
				{
					f[len] = carry;
					len++;
				}
				
				for(int j = 0; j < len; j++)
				{
					a[j] = b[j];
					b[j] = f[j];
				}
			}
			
			for(int i = len-1; i >= 0; i--)
			{
				cout << f[i];
			}
			cout << "\n";
		}
	}
}
