#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long int s, d, a;
	while(scanf("%lld %lld", &s, &d) == 2)
	{
		a = 0;
		while(a < d)
		{
			a += s;
			s++;
		}
		
		printf("%lld\n", s-1);

	}
}

//https://knightzone.studio/2018/09/26/3621/uva%EF%BC%9A10170%EF%BC%8Dthe-hotel-with-infinite-rooms/
