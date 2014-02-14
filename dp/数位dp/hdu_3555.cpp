#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define ll __int64
ll dp[101][3];
int p[101];
int main()
{
    int i,t,len,z;
    ll sum,n;
    scanf("%d",&t);
    dp[0][0] = 1;
    for(i = 1; i <= 19; i ++)
    {
        dp[i][0] = dp[i-1][0]*10 - dp[i-1][1];
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][1]+dp[i-1][2]*10;
    }
    while(t--)
    {
        memset(p,0,sizeof(p));
        scanf("%I64d",&n);
        n++;
        sum = 0;
        len = 1;
        while(n >= 10)
        {
            p[len ++] = n%10;
            n = n/10;
        }
        p[len] = n;
        z = 0;
        for( i = len; i>=1; i--)
        {
            sum += dp[i-1][2] * p[i];
            if(z)
                sum += dp[i-1][0] * p[i];
            if(!z && p[i] >4)
                sum += dp[i-1][1];
            if(p[i+1] == 4 && p[i] == 9)
                z = 1;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}