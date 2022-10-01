#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
	char s1[30], s2[30];
	int cases = 0;
	while(scanf("%s %s", s1, s2) == 2)
	{
		if(cases)
		{
			printf("\n");
		}
		cases++;
		
		int len = strlen(s1);
		
		printf("%s (to %s)\n", s1, s2);
		if(len < 2 || (strcmp(s1+len-2, "ar") && strcmp(s1+len-2, "er") && strcmp(s1+len-2, "ir")))
		{
			printf("Unknown conjugation\n");
			continue;
		}
		
		char tv = s1[len-2];
		s1[len-2] = '\0';
		
		printf("eu        %so\n", s1);
		
		if(tv == 'i')
		{
			printf("tu        %ses\n", s1);
		}
		else
		{
			printf("tu        %s%cs\n", s1, tv);
		}
		
		if(tv == 'i')
		{
			printf("ele/ela   %se\n", s1);
		}
		else
		{
			printf("ele/ela   %s%c\n", s1, tv);
		}
		
		printf("n%cs       %s%cmos\n", (char)243, s1, tv);
		
		if(tv == 'i')
		{
			printf("v%cs       %s%cs\n", (char)243, s1, tv);
		}
		else
		{
			printf("v%cs       %s%cis\n", (char)243, s1, tv);
		}

		if(tv == 'i')
		{
			printf("eles/elas %sem\n", s1);
		}
		else
		{
			printf("eles/elas %s%cm\n", s1, tv);
		}
		
	}
 } 
