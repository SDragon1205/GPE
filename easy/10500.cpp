#include <iostream>
#include <stdlib.h>

using namespace std;

//int cc(int u, int d)
//{
//	int a = 1;
//	int b = 1;
//	for(int i = u; i > (u-d); i--)
//	{
//		a *= i;
//	}
//	for(int j = d; j > 1; j++)
//	{
//		b *= j;
//	}
//	
//	return a/b;
//}
//
//int main()
//{
//	int a, ans, d;
//	cin >> a;
//	while(a != 0)
//	{
//		ans = 1;
//		d = 0;
//		for(a -= 2; a>=0; a-=2)
//		{
//			d++;
//			ans += cc(a+d, d);
//		}
//		cout << ans << "\n";
//		
//		cin >> a;
//	}
//	
//	return 0;
//}

int main()
{
	int dp[51];
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i = 4; i <=50; i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	
	int a;
	cin >> a;
	while(a !=0)
	{
		cout << dp[a] << "\n";
		cin >> a;
	}
	
	
	return 0;
}
