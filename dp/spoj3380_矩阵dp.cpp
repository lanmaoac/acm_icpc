#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N=1001111;
int m,n;
char s[111][111];
int a[111][111];
int dp[222][111][111];
void init()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=m;i++)
       for(int j=1;j<=n;j++)
        switch (s[i][j]){
            case '.':a[i][j]=0; break;
            case '*':a[i][j]=1; break;
            case '#':a[i][j]=2; break;
        }
    memset(dp,0,sizeof(dp));
}
void cha(int &x,int y){
    if(y>x) x=y;
}
void gao(){
    dp[2][1][1]=a[1][1];
    for(int k=3;k<=m+n;k++)
      for(int i=1;i<=m;i++) if(k-i< 1 || k-i> n) continue;else
        for(int j=1;j<=m;j++) if(k-j<1 || k-j>n) continue; else{
            if(a[i][k-i]==2||a[j][k-j]==2) continue;
             int &t = dp[k][i][j];
             cha(t,dp[k-1][i][j]);
             cha(t,dp[k-1][i-1][j]);
             cha(t,dp[k-1][i-1][j-1]);
             cha(t,dp[k-1][i][j-1]);
             t+=a[i][k-i];
             if(i!=j) t+=a[j][k-j];
         }
    cha(dp[m+n][m][m],0);
    cout<<dp[m+n][m][m]<<endl;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--){
        init();
        gao();
    }
    return 0;
}
