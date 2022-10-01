#include<iostream>
#include<stdio.h>
#include <climits>
#include<algorithm>

using namespace std;

int n, ans;
int s[1000];

int solve()
{
	for(int d = n-1; d >= 0; d--)
	{
		for(int a = 0; a < n; a++)
		{
			for(int b = a+1; b < n; b++)
			{
				for(int c = b+1; c < n; c++)
				{
					if(s[d] == s[a] + s[b] + s[c])
					{
						return s[d];
					}
				}
			}
		}
	}
	return INT_MAX;
}

int main()
{
	scanf("%d", &n);
	while(n != 0)
	{
		for(int i = 0; i <n; i++)
		{
			scanf("%d", &s[i]);
		}
		sort(s, s + n);
		
		ans = solve();
		
		if(ans == INT_MAX)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%d\n", ans);
		}
		
		scanf("%d", &n);
	}
}

//http://www.aspphp.online/bianchen/cyuyan/cjj/cjjrm/201701/204885.html

