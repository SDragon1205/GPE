#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int m, n, t;
	while(scanf("%d %d %d", &m, &n, &t) == 3)
	{
		int minb = min(m, n);
		int maxb = max(m, n);
		
		int maxnum = (int)t/minb;
		int rt = t - (maxnum * minb);

		for(int i = maxnum - 1; i >= 0 && rt != 0; i--)
		{
			int crt = t - i * minb;
			int anum = (int)crt/maxb;
			crt -= anum * maxb;
			
			if(crt < rt)
			{
				rt = crt;
				maxnum = i + anum;
			}
		}
		
		printf("%d", maxnum);
		if(rt > 0)
		{
			printf(" %d", rt);
		}
		printf("\n");
	}
}

//https://knightzone.studio/2020/04/28/4856/uva%EF%BC%9A10465%EF%BC%8Dhomer-simpson/
