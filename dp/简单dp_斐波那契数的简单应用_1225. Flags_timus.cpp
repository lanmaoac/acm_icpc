#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int dp[50];
int ans(int n)
{ if(n<=0) return 0;
  if(dp[n]!=-1) return dp[n];
  return dp[n]=ans(n-1)+ans(n-2);
}
int main()
{
  int n;
  memset(dp,-1,sizeof(dp));
  dp[1]=2;dp[2]=2;dp[3]=4;
  scanf("%d",&n);
  printf("%d",ans(n)); 
  return  0;
}