#include <iostream>

using namespace std;
int pa[101];

int main()
{
	int t, n, p;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n >> p;
		for(int j = 1; j <=p; j++)
		{
			cin >> pa[j];
		}
		
		int ans = 0;
		for(int d = 1; d <= n; d++)
		{
			if(d%7 != 6 && d%7 != 0)
			{
				for(int j = 1; j <=p; j++)
				{
					if(d%pa[j] == 0)
					{
						ans++;
						break;
					}
				}
			}
		}
		
		cout << ans << "\n"; 
	}
	
}
