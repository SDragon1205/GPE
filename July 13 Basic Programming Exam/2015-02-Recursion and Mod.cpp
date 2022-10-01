#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
 
#define mod 1000000009

//fn = (3^n)-2

int fast(unsigned long long int n)
{
	unsigned long long int sum = 1;
	unsigned long long int thr = 3;
	while(n > 0)
	{
		if(n%2)
		{
			sum = (sum*thr) % mod;
			n--;
		}
		n /= 2;
		thr = (thr*thr) % mod;
	}
	
	return sum - 2;
}

int main()
{
    unsigned long long int f;
    unsigned long long int n;
    while(cin >> n)
    {
        f = fast(n);

        cout << f << "\n";
    }

}

//http://slides.com/allenwhale/deck-3-4/fullscreen#/5/3
