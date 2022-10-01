#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int c[26];

int main()
{
	int n;
	scanf("%d", &n);
	string line;
	cin.ignore();
	for(int i = 0; i < n; i++)
	{
		getline(cin, line);
		for(int j = 0; j < line.length(); j++)
		{
			if(isalpha(line[j]))
			{
				c[toupper(line[j]) - 'A']++;
				//printf("%d %d\n", toupper(line[j]) - 'A', c[toupper(line[j]) - 'A']);
			}
		}
	}
	
	int max = 0;
	for(int i = 0; i < 26; i++)
	{
		if(c[i] > max)
		{
			max = c[i];
		}
	}
	
	for(int i = max; i > 0; i--)
	{
		for(int j = 0; j < 26; j++)
		{
			if(c[j] == i)
			{
				printf("%c %d\n", j+'A', i);
			}
		}
	}
} 
