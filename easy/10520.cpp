#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n;
	int cr[5];
	while(cin >> n && n)
	{
		int ans = 0;
		map<long long, int> m;
		for(int j = 0; j <n ; j++)
		{
			for(int i = 0; i <5 ; i++)
			{
				cin >> cr[i];
			}
			sort(cr, cr+5);
			long long v = 0;
			for(int i = 0; i <5 ; i++)
			{
				v *= 1000;
				v += cr[i];
			}
			m[v]++;
			ans = max(ans, m[v]);
		}
		int cc =0;
		for(map<long long, int> :: iterator it = m.begin(); it != m.end(); it++)
		{
			if(it->second == ans)
			{
				cc += ans;
			}
		}
		cout << cc << "\n";
	}
}
