#include <iostream>
#include <cstdio>

using namespace std;

int e[9];
int th[9];
bool visited[9];
int ans[9][9];
int n, ma;

void dfs(int pos, int lon)
{
    if(pos >= n)
    {
        if(lon > ma)
        {
            ma = lon;
        }
        return;
    }

    lon++;
    for(int i = pos; i < n; i++)
    {
        visited[i] = false;
        dfs(th[i], lon);
    }
}

int main()
{
    int cases, i, j;
    cin >> cases;
    for(int ca = 0; ca < cases; ca++)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> e[i];
            visited[i] = true;
        }
        for(i = 0; i < n; i++)
        {
            j = i+1;
            while(e[i] >= e[j] && j < n)
            {
                j++;
            }
            th[i] = j;
            cout << th[i] << " ";
        }
        cout << "\n";

        ma = 0;
        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                dfs(th[i], 1);
            }
        }
        cout << ma << "\n";
    }
}