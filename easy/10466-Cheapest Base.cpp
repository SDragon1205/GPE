#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int main()
{
	int cases, l, n, min, tmp, cost;
	int c[36];
	scanf("%d", &cases);
	for(int ca = 1; ca <= cases; ca++)
	{
		printf("Case %d:\n", ca);
		
		for(int i = 0; i < 36; i++)
		{
			scanf("%d", &c[i]);
		}
		
		scanf("%d", &l);
		for(int i = 0; i < l; i++)
		{
			int ans[37] = {0};
			scanf("%d", &n);
			min = INT_MAX;
			for(int j = 2; j <= 36; j++)
			{
				tmp = n;
				cost = 0;
				while(tmp > 0)
				{
					cost += c[tmp % j];
					tmp /= j;
				}
				//cout << "j: " << j << ", cost: " << cost << "\n";
				
				if(cost <= min)
				{
					min = cost;
					ans[j] = cost;
				}
			}
			
			printf("Cheapest base(s) for number %d:", n);
			
			for(int j = 2; j <= 36; j++)
			{
				//cout << "j: " << j << ", cost: " << ans[j] << "\n";
				if(ans[j] == min)
				{
					printf(" %d", j);
				}
			}
			
			printf("\n");
		}
		
		if(ca < cases)
		{
			printf("\n");
		}
	}
}

//https://fg123789hj.pixnet.net/blog/post/280205432-uva11005%EF%BC%9Acheapest-base
