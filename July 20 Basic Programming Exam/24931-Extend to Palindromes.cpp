#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[100010];
char s[100010],r[100010];
int len;

// void fail()
// {
//     int i, j;
//     f[0] = -1;
//     j = -1;
//     for(i = 1; i < len; i++)
//     {
//         while(j >= 0 && r[j+1] != r[i])
//         {
//             j--;
//         }
//         if(r[j+1] == r[i])
//         {
//             j++;
//         }

//         f[i] = j;
//         //cout << "f" << i << ": " << f[i] << "\n";
//     }
// }

int kmp()
{
    int i, j;
    j = -1;
    for(i = 0; i < len; i++)
    {
        while(j >= 0 && r[j+1] != s[i])
        {
            j--;
        }
        if(r[j+1] == s[i])
        {
            j++;
        }
        cout << "j: " << j << "\n";
    }

    return j;
}

int main()
{
    while(cin >> s)
    {
        len = strlen(s);
        for(int i = 0, j = len-1; i < len; i++, j--)
        {
            r[i] = s[j];
        }
        r[len] = '\0';
        //cout << "r: " << r << "\n";
        // fail();
        cout << s;
        for(int i = kmp()+1; i < len; i++)
        {
            cout << r[i];
        }
        cout << "\n";
    }
}