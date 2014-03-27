#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int dp[1005];
int gao(int a)
{
     if(dp[a]!=-1) return dp[a];
     int  tmp = a;
     for(int i=2;i<=a-1;i++)
     	if(a%i==0)
     		tmp=min(tmp,gao(i)+a/i);
     return dp[a]=tmp;	
}
class EmoticonsDiv2
{
  public:
  int printSmiles(int smiles){
    memset(dp,-1,sizeof(dp));
    dp[1]=0;
    dp[2]=2;
    dp[3]=3;
    return gao(smiles);   
  }

};