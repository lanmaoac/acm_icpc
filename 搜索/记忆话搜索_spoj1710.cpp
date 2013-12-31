#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//记忆化搜索
int dp[1005][1005];
int num[1005];
int solve(int a,int b,int flag)
{
   if(a>b) return 0;
   int &ret=dp[a][b];
   if(ret!=-1)
    return ret;
  if(flag)
  	ret=max(num[a]-solve(a+1,b,1-flag),num[b]-solve(a,b-1,1-flag));
  else
  {
           if(num[a]>num[b]) ret=num[a]-solve(a+1,b,1-flag);
           else 	ret=num[b]-solve(a,b-1,1-flag);
  }
  return ret;
}
int main()
{
     int n;
     int cas=1;
     while(scanf("%d",&n)&&n!=0)
    {
     for(int i=1;i<=n;i++)
     	scanf("%d",num[i]);
     int ans=solve(1,n,1);
     printf("In game %d, the greedy strategy might lose by as many as %d points.\n",cas++,ans);
     }
    return 0;
}
