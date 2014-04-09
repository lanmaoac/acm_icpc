#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
   int n;long long k;
  cin>>n>>k;
   if(((n-1)*n)/2>k){
        for(int i=1;i<=n;i++){
          printf("%d %d\n",0,i);
        }
   }else printf("no solution\n");
   return 0;
}