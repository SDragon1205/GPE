#include <iostream>

using namespace std;

int reverse(int n)
{
	int re = 0;
	while(n)
	{
		re = re*10 + n%10;
		n /= 10;
	}
	
	return re;
}

int main()
{
	int time, n;
	int rev, tt;
	cin >> time;
	for(int i = 0; i < time; i++)
	{
		tt = 0;
		cin >> n;
		rev = reverse(n);
		//cout << rev << "\n";
		while(n != rev)
		{
			n += rev;
			rev = reverse(n);
			tt++;
		}
		cout << tt << " " << n << "\n";
	}
	
	return 0;
}
