#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#define maxn 10009
using namespace std;
long long int dp[20][5];
int len[20];int top;
unsigned long long now;
void fuck(long long a){
  memset(len,0,sizeof(len));
  while(a>=10){
    len[top++]=a%10;
    a/=10;
  }
  len[top]=a;
}
bool judge()
{
  for(int i=top;i>=1;i--)
    if(len[i]==1 && len[i-1]==3) return true;
  return false;
}
long long gao(long long now){

    long long sum=0;bool z=false;top=1;
    fuck(now);
    for( int i = top; i>=1; i--)
        {
            sum += dp[i-1][2] * len[i];
            if(z)
                sum += dp[i-1][0] * len[i];
            if(!z && len[i] >1)
                sum += dp[i-1][1];
            if(!z &&len[i+1]==1 &&len[i]>3) sum+=dp[i][1];
            if(len[i+1] == 1 && len[i] == 3)
                z = 1;
        }
   if(judge())sum++;
   return now-sum;
}
int main()
{

    int cas;
    scanf("%d",&cas);
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=19;i++){
      dp[i][0]=dp[i-1][0]*10-dp[i-1][1];
      dp[i][1]=dp[i-1][0];
      dp[i][2]=dp[i-1][1]+dp[i-1][2]*10;
    }
  while(cas--)
  {
    scanf("%lld",&now);
    unsigned long long  l=1;
    unsigned long long  r=10000000000000000;
    unsigned long long ans;
    unsigned long long he;
    while(r>=l) {
        unsigned long long mid=(l+r)/2;
        unsigned long long ans=gao(mid);
         if(ans>=now) he=mid,r=mid-1;
         else l=mid+1;
    }
    cout<<he<<endl;
  }
  return 0;
}
