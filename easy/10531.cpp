#include <iostream>
#include <stdio.h>
#include <cctype>
#include <map>
#include <iterator>
#include <string>

using namespace std;

map<string, int> m;

void getw(string s)
{
	string tmp = "";
	for(int x = 0; x < s.size(); x++)
	{
		if(isalpha(s[x]))
		{
			tmp += tolower(s[x]);
		}
		else
		{
			if(tmp.size() > 0)
			{
				m[tmp]++;
				tmp = "";
			}
		}
	}
	if(tmp.size() > 0)
	{
		m[tmp]++;
	}
	tmp = "";
}

int main()
{
	int ff = 1;
	string s;
	int n;
	while(scanf("%d",&n) != EOF)
	{
		while(getline(cin, s))
		{
			if(s == "EndOfText")
			{
				break;
			}
			getw(s);
		}
		
		if(ff)
		{
			ff = 0;
		}
		else
		{
			cout << "\n";
		}
		
		int no = 1;
		for(map<string, int> :: iterator it = m.begin(); it != m.end(); it++)
		{
			if(it->second == n)
			{
				cout << it->first << "\n";
				no = 0;
			}
		}
		if(no)
		{
			cout << "There is no such word.\n";
		}
		m.clear();
	}
}
