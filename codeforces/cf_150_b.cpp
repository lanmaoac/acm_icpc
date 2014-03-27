#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int x,y;
int n;
set <long long >ret;
void gao(long long now,long long times){
  if(now > n || times >10)
    return ;
    ret.insert(now);
    gao(now*10+x,times+1);
    gao(now*10+y,times+1);
}
int main()
{

   scanf("%d",&n);
   for(x=0;x<10;x++)
    for(y=x+1;y<10;y++)
      gao(0,0);
    printf("%d",ret.size()-1);
   return 0;
}
