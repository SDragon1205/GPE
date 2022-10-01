#include <cstdlib>
#include <cstdio>

int p[3500];
int visit[35000] = {0};

int main()
{
	int ps = 0;
	for(int i = 2; i <= 35000; i++)
	{
		if(!visit[i])
		{
			p[ps++] = i;
			for(int j = i*i; j <= 35000; j += i)
			{
				visit[j] = 1;
			}
		}
	}
	//cout << p[3499] << "\n"; 
	//printf("%d\n", p[3499]);
	
	int n;
	while(~scanf("%d", &n) && n)
	{
		int ans = 0;
		for(int i = 2; i <=n; i++)
		{
			ans = (ans+p[n-i])%i;
		}
		printf("%d\n", ans+1);
	}
	
	return 0;
}
