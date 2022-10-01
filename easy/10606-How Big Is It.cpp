#include<iostream>
#include<cstdio>
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;

int n, m;
double tmp;
double cir[8], cur[8];

double dis(double a, double b)
{
	double lon = a+b;
	double shor = fabs(a-b);
	
	return sqrt((lon*lon) - (shor*shor));
}

double big()
{
	cur[0] = cir[0];
	for(int i = 1; i < m; i++)
	{
		cur[i] = cir[i];
		for(int j = 0; j < i; j++)
		{
			tmp = dis(cir[j], cir[i]) + cur[j];
			if(tmp > cur[i])
			{
				cur[i] = tmp;
			}
		}
		
//		if(cur[i]+cir[i] > max)
//		{
//			max = cur[i]+cir[i];
//		}
	}
	
	double max = -1;
	for(int i = 0; i < m; i++)
	{
		if(cur[i]+cir[i] > max)
		{
			max = cur[i]+cir[i];
		}
	}
	
	
	return max;
	
}

int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> m;
		//cout << "m: " << m << "\n";
		for(int j = 0; j < m; j++)
		{
			cin >> cir[j];
		}
		
		sort(cir, cir+m);
		
		double now;
		double min = INT_MAX;
		do
		{
			now = big();
        	//cout << "now: " << now << "\n";
			if(now < min)
			{
				min = now;
			}
		}while(next_permutation(cir, cir+m));
		
		printf("%.3lf\n", min);
	}
} 

//https://mypaper.pchome.com.tw/zerojudge/post/1322943180
