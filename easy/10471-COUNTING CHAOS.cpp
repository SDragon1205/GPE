#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, hh, mm, a, b, c, d;
	cin >> n;
	for(int nn = 0; nn < n; nn++)
	{
		scanf("%d:%d", &hh, &mm);
		//cout << "h: " << hh << ", m: " << mm << "\n";
		while(true)
		{
			mm++;
			if(mm == 60)
			{
				hh++;
				mm = 0;
			}
			if(hh == 24)
			{
				hh = 0;
			}
			
			
			a = hh / 10;
			b = hh % 10;
			c = mm / 10;
			d = mm % 10;
			//cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << "\n";
			
			
			if(a == 0)
			{
				if(b == 0)
				{
					if(c == 0)
					{
						printf("%02d:%02d\n", hh, mm);
						break;
					}
					else if(c == d)
					{
						printf("%02d:%02d\n", hh, mm);
						break;
					}
				}
				else if(b == d)
				{
					printf("%02d:%02d\n", hh, mm);
					break;
				}
			}
			else if(a == d && b == c)
			{
				printf("%02d:%02d\n", hh, mm);
				break;
			}
			
		}
		
	}
}

//https://mypaper.pchome.com.tw/zerojudge/post/1322923782
