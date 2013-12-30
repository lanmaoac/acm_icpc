#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <map>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[10];
long long num[10]={0};
long long ans=0x7fffffff;
int n;
void gao()
{
	for(int i=1;i<=n;i++)
	{
	   long long x=dp[i];
       for(long long j=2;j*j<=x;j++)
           for(;x%j==0;x/=j)
           	++num[i];
       if(x!=1) ++num[i];
	}
}
bool dfs_1(int idx)
{
    if(idx==0) {ans=num[n]+n;return 1;}
    for(int i=n;i>idx;i--)
    {
    	if(dp[i]%dp[idx]==0)
    	{   dp[i]/=dp[idx];
    		if(dfs_1(idx-1))
    			return 1;
    		dp[i]*=dp[idx];
        }
    }
    return 0;
}
void dfs_2(int idx,long long int sum)
{
	if(idx==0) {ans=min(ans,sum+n+1);return ;}
	for(int i=n;i>idx;i--)
	{
       if(dp[i]%dp[idx]==0)
       {
       	   dp[i]/=dp[idx];
       	   dfs_2(idx-1,sum);
       	   dp[i]*=dp[idx];
       }
	}
	dfs_2(idx-1,sum+num[idx]);
}
int main()
{
  long long int cnt=0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  	scanf("%I64d",&dp[i]);
  sort(dp+1,dp+n+1);
  gao();
  for(int i=1;i<=n;i++) if(num[i]==1) cnt++;
  if(!dfs_1(n-1))
  dfs_2(n,(long long)0);
  printf("%I64d",ans-cnt);
  return 0;
}
