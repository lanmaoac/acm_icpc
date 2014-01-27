#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
using namespace std;
int dp[15][100]={0};
int main()
{
  int n,k,t;
  scanf("%d",&t);
  
  for(int i=1;i<=12;i++)
    dp[i][0]=1;
  for(int i=1;i<=12;i++)
    for(int j=0;j<=98;j++){
       for(int k=1;k<=i-1;k++)
        if(j-k<0) continue;
        else dp[i][j]+=dp[i-1][j-k];
   }
  while(t--){
    scanf("%d%d",&n,&k); 
    printf("%d",dp[n][k]);
  }
  return 0;
}