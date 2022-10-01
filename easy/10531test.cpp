#include <iostream>
#include <cstdio>
#include <cctype>
#include <map>
using namespace std;
map<string,int> myMap;

void getWords(string cad){
string tmp = "";

for(int x=0; x<cad.size(); x++)
   {
     if(isalpha(cad[x]))
        tmp+=tolower(cad[x]);
     else{
           if(tmp.size() > 0)
           {
             myMap[tmp]++;
             tmp = "";
           }

         }

   }
 if(tmp.size() > 0)
    myMap[tmp]++;
 tmp = "";
}

int main(){
int n, casos = 0;
string cad;

while(scanf("%d",&n) != EOF){
    getline(cin,cad);//trash
    while(getline(cin,cad)){
    if(cad == "EndOfText")
       break;
    getWords(cad);
    }
    bool flag = false;

    if(casos == 0)
       casos = 1;
    else
        printf("\n");
    for(map<string,int>::iterator it = myMap.begin(); it != myMap.end(); it++)
    {
        if(it->second == n)
           {
            printf("%s\n", it->first.c_str());
            flag = true;
           }
    }
    if(flag == false)
       printf("There is no such word.\n");
    myMap.clear();
}
return 0;
}
