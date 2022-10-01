#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		string l;
		getline(cin, l);
		stringstream ss(l);
		vector<int> w;
		int ww, sum;
		sum = 0;
		while(ss >> ww)
		{
			w.push_back(ww);
			sum += ww;
		}

		if(sum % 2 == 1)
		{
			printf("NO\n");
			continue;
		}
		
		//cout << "sum: " << sum << "\n";
		vector<bool> p(sum + 1, false);
		p[0] = true;
		//cout << "n: " << sum << "\n";
		for(int a = 0; a < w.size(); a++)
		{
			//cout << a << "\n";
			for(int b = sum; b >= w[a]; b--)
			{
				//cout << a << " " << b << "\n";
				if(p[b - w[a]])
				{
					p[b] = true;
				}
			}
		}
		
		//cout << "ch\n";
		if(p[sum/2])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}

//https://knightzone.studio/2020/04/16/4816/uva%EF%BC%9A10664%EF%BC%8Dluggage/
