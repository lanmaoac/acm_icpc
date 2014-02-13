#include<cstdio>
#include<cstring>
using namespace std;
int dp[10][3];
int DP(int x)
{
    bool flag=false;
    int s[15];
    int idx=0,summ=x,ans=0;
    for(;x;x/=10)
        s[++idx]=(x%10);
    s[idx+1]=0;
    for(int i=idx;i>0;--i)
    {
        ans+=(dp[i-1][2]*s[i]);//由上位所有不吉利数推导
        if(flag) ans+=(dp[i-1][0]*s[i]);//之前出现不吉利的数字
        else
        {
            if(s[i]>4)            ans+=dp[i-1][0];//出现4
            if(s[i]>6)            ans+=dp[i-1][1];//出现6
            if(s[i+1]==6&&s[i]>2) ans+=dp[i][1];//出现62
        }
        if(s[i]==4||s[i+1]==6&&s[i]==2)
            flag=true;
    }
    return summ-ans;//所有的数减去不吉利的数
}
int main()
{
    int a,b;
    memset(dp,0,sizeof(dp));
    //预处理，算出所有可能
    dp[0][0]=1;
    for(int i=1;i<=8;++i)
    {
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];//在不含不吉利数的末位分别补除了4的9个数字，减去在6后面补2的个数
        dp[i][1]=dp[i-1][0];//在不含不吉利数在末位补6
        dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];//各种出现不吉利数的情况
    }
    for(;scanf("%d%d",&a,&b);)
    {
        if(a+b==0) break;
        printf("%d\n",DP(b+1)-DP(a));
    }
    return 0;
}
