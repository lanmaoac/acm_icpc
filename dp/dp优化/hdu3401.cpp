#include <cstdio>  
#include <cstring>  
#include <set>  
#include <algorithm>  
using namespace std;  
const int N = 2010;
int ap[N],bp[N],as[N],bs[N];
int w,maxp,t,head,tail;
int dp[N][N];
int q[N][5];
void gao()
{
  for(int i=0;i<-t;i++)
  	for(int j=0;j<=maxp;j++)
  		dp[i][j]=-100000;
  for(int i=1;i<=w+1;i++)
    for(int j=0;j<=min(as[i],maxp);j++)
        dp[i][j]=-j*ap[i];	
  for(int i=2;i<=t;i++){
      head=0;
      tail=1;
      for(int j=0;j<=maxp;j++){
      	dp[i][j]=max(dp[i][j],dp[i-1][j]);
      if(i<=w+1) continue;
      while(head<=tail && q[tail][1]<=dp[i-w-1][j]+ap[i]*j) tail--;
      q[++tail][0]=j;
      q[tail][1]=dp[i-w-1][j]+ap[i]*j;
      while(head < tail && j-q[head][0]>as[i])
      	head++;
      dp[i][j]=max(dp[i][j],q[head][1]-ap[i]*j);
      }
      head=0;tail=1;
      for(int j=maxp;j>=0;j--){
         if(i<=w+1) continue;
         while(head<=tail && q[tail][1]<=dp[i-w-1][j]+bp[i]*j) tail--;
         q[++tail][0]=j;
         q[tail][1]=dp[i-w-1][j]+bp[i]*j;
         while(head<tail && q[head][0]-j>bs[i]) head++;
         dp[i][j] = max(dp[i][j], q[head][1] - bp[i] * j);  
      }
  } 
  int ans=-100000000;
  for(int i=0;i<=maxp;i++)
  ans=max(ans,dp[t][i]);
  printf("%d\n",ans); 
}
int main()
{ 
	int cas;
	scanf("%d",&cas);
	while(cas--){
       scanf("%d%d%d",&t,&maxp,&w);
       for(int i=1;i<=t;i++)
       	scanf("%d%d%d%d",&ap[i],&bp[i],&as[i],&bs[i]);
       gao();
	}
	return 0;
}