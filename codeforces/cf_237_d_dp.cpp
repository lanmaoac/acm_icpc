#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iostream>
#define maxn 1000009
#define maxm
#define INF
#define MOD 1000000007
using namespace std;
char s[maxn];
__int64 dp[maxn][5];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    if(s[1]=='?'||s[1]=='0')dp[1][0]=1;
    if(s[1]=='?'||s[1]=='1')dp[1][1]=1;
    if(s[1]=='?'||s[1]=='*')dp[1][3]=1;
    for(int i=2;i<=n;i++)
    {
        if(s[i]=='?'||s[i]=='0')
            dp[i][0]=(dp[i-1][0]+dp[i-1][4])%MOD;
        if(s[i]=='?'||s[i]=='1')
        {
            dp[i][4]=dp[i-1][3];
            dp[i][1]=(dp[i-1][0]+dp[i-1][4])%MOD;
        }
        if(s[i]=='?'||s[i]=='2')
            dp[i][2]=(dp[i-1][3])%MOD;
        if(s[i]=='*'||s[i]=='?')
            dp[i][3]=(dp[i-1][1]+dp[i-1][3]+dp[i-1][2])%MOD;
    }
    long long ans=dp[n][0]+dp[n][4]+dp[n][3];
    cout<<ans%MOD;

}