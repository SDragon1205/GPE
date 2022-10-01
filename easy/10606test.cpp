#include<iostream>
#include<cstdio>
#include<cmath> 
#include<cstring>
#include<algorithm>
#define MAXN 10
#define INF 0x7FFFFFFF
using namespace std;
double circle[MAXN], actually[MAXN];
double minlen;

double dis(double left, double right)
{
    double a, c;
    c = left + right;
    a = fabs(left - right);
    return sqrt(c * c - a * a);
}

void Traverse(int n)
{
    double len = 0;
    actually[0] = circle[0];
    for(int i=1; i<n; ++i)
    {
         actually[i] = circle[i];
         for(int j=0; j<i; ++j)
         {
             double temp = dis(circle[j], circle[i]) + actually[j];
             if(temp > actually[i])  actually[i] = temp;
          }
    }
    double temp = -INF;
    for(int i=0; i<n; ++i)
    {
        if(actually[i] + circle[i] > temp)
        temp = actually[i] + circle[i];
    }
    if(temp < minlen) minlen = temp;
    return;
}

int main()
{
//    #ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    #endif
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        memset(circle, 0, sizeof(circle));
        for(int i=0; i<n; ++i)
            cin>>circle[i];
        minlen = INF;
        sort(circle, circle+n);
        do
       {
//        	for(int i=0; i<n; ++i)cout<<circle[i] << " ";
//        	cout << "\n";
            Traverse(n);
        }while(next_permutation(circle, circle+n));
        printf("%.3lf\n", minlen); 
    }
    return 0;
} 
