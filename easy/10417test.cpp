#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
  long long int S, D;
  while(scanf("%lld%lld", &S, &D) != EOF){
    printf("%lld\n", (long long int)ceil((-1 + sqrt(1 - 4 * (-S*S + S - 2*D))) / 2));
  }

  return 0;
}
