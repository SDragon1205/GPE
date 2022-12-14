#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
#define LEN 100000
 
int f[LEN+10];
 
void failure(char *P)
{
    int i, j;
 
    f[0] = -1;
    //cout << "f0: -1\n";
    for(i = 1, j = -1; P[i]; i++)
    {
        while(j >= 0 && P[j+1] != P[i])
        {
            //cout << "j: " << j << ": " << f[j] << "\n";
            //j = f[j];
            j--;
        }
            
 
        if(P[j+1] == P[i])
        {
            //cout << "j+one: " << j+1 << ": " << P[j+1] << "\n";
            j++;
        }
            
 
        f[i] = j;
        //cout << "f" << i << ": " << f[i] << "\n";
    }
}
 
int KMP(char *S, char *P)
{
    int i, j;
 
    failure(P);
 
    for(i = 0, j = -1; S[i]; i++)
    {
        while(j >= 0 && P[j+1] != S[i])
            j = f[j];
 
        if(P[j+1] == S[i])
            j++;
 
    }
 
    return j;
}
 
int main()
{
    char S[LEN+10];
    char P[LEN+10];
    int i, j;
    int len;
    int cut;
 
    while(scanf("%s", S) == 1)
    {
        len = strlen(S);
 
        for(i = 0, j = len - 1; i <= len - 1; i++, j--)
        {
            P[i] = S[j];
        }
        P[len] = '\0';
 
        cut = KMP(S, P);
        printf("%s", S);
        for(i = cut + 1; i <= len - 1; i++)
            printf("%c", P[i]);
        printf("\n");
    }
 
    return 0;
}