#include <iostream>
#include <cstdio>
#include <cmath>
#define size 10000002

using namespace std;

int p[size]; // prime
bool np[size]; // notprime
int f[size]; //num of prime

int fact(int a)
{
	if(!np[a])
	{
		return 1;
	}
	
	int max = (int)sqrt(a);
	int am = 0; // amount of primt of a
	for(int i = 0; p[i] <= max; i++)
	{
		while(a % p[i] == 0)
		{
			a /= p[i];
			max = (int)sqrt(a);
			am++;
		}
	}
	
	if(a > 1)
	{
		am++;
	}
	return am;
}

int main()
{
	//cin.sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int idx = 0;
	for(int i = 2; i < size; i++)
	{
		f[i] = -1;
		if(!np[i])
		{
			//cout << i <<"\n";
			p[idx] = i;
			idx++;
		}
		for(int j = 0; i*p[j] < size && j < idx; j++)
		{
			np[i*p[j]] = true;
		}
	}
	//cout << "101\n";
	int nump = 0;
	for(int i = 2; nump < size; i++)
	{
		nump += fact(i);
		//cout << "nump: " << nump << ", i: " << i << "\n";
		f[nump] = i;
	}
	
	//cout << "101\n";
	int in, ca;
	cin >> in;
	ca = 1;
	while(in >= 0)
	{
		if(f[in] == -1)
		{
			printf("Case %d: Not possible.\n", ca);		
		}
		else
		{
			printf("Case %d: %d!\n", ca, f[in]);
		}
		
		ca++;
		cin >> in;
	}
}

//https://home.gamer.com.tw/creationDetail.php?sn=4229931
