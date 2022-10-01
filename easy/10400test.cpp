#include <iostream>
using namespace std;
int main()
{
    int i,j;
    while(cin>>i>>j)
    {
        cout<<i<<" "<<j<<" ";
        if(i>j)
        {
            int k;
            k=i;
            i=j;
            j=k;
        }
        int max=0;
        int t;
        int count;
        for(int y=i;y<j+1;y++)
        {
            count=1;
            t=y;
            while(t!=1)
            {
                    if(t%2==0)
                    {
                        t=t/2;
                    }
                    else
                    {
                        t=t*3+1;
                    }
                   count++;
            }
            if(count>max)
            {
                max=count;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
