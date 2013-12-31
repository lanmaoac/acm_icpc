#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[305];
int n;
bool check()
{

    for(int i=1;i<=n;i++)
     if(dp[i]>0)
        return false;
    return true;
}
int main()
{

   scanf("%d",&n);
   for(int i=1;i<=n;i++)
       cin>>dp[i];
   int now=1;
   bool in=true;
   while(true)
   {
      if(!check())
      {
           if(dp[now])
            {printf("P");dp[now]--;}//if一定的括号要注意啊，，不能作死
           if(check()) break;
           if(now==1)
           {
            printf("R");
            in=true;
            now++;
            continue;
           }
           if(now==n)
           {
            printf("L");
            in=false;
            now--;
            continue;
           }
           if(in)
           {
            printf("R");
            now++;
            continue;
           }
           else
           {
            printf("L");
            now--;
            continue;
           }


      }
      else
      break;
   }
  return 0;
}
