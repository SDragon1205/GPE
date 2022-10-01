#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
 
typedef long long LL;
 
using namespace std;
 
int courses[5];
 
int main()
{
	int n;
	while (cin >> n && n) {
		map<LL, int> Map;
		int maxv = 1, count = 0;
		for (int t = 0; t < n; ++ t) {
			for (int i = 0; i < 5; ++ i)
				cin >> courses[i];
			sort(courses, courses+5);
			LL value = 0;
			for (int i = 0; i < 5; ++ i) {
				value *= 1000;
				value += courses[i];
			}
			maxv = max(maxv, Map[value] += 1);
		}
		for (map<LL, int>::iterator it = Map.begin(); it != Map.end(); ++ it)
			if (it->second == maxv) 
				count += maxv;
		
		cout << count << endl;
	}
    return 0;
}

