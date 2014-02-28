#include<algorithm>  
#include<iostream>  
#include<cstring>  
#include<cstdio>  
#include<cmath>  
#define LL long long  
#define CLR(a, b) memset(a, b, sizeof(a))  
  
using namespace std;  
  
const int N = 500500;  
  
int sum[N], dp[N], d[N];  
int n, m;  
  
int DB(int a){return a * a;}  
  
int getUP(int i, int j)  
{  
    return dp[i] + DB(sum[i]) - dp[j] - DB(sum[j]);  
}  
  
int getDOWN(int i, int j)  
{  
    return 2 * (sum[i] - sum[j]);  
}  
  
int getDP(int i, int j)  
{  
    return dp[j] + DB(sum[i] -sum[j]) + m;  
}  
  
int main()  
{  
    //freopen("input.txt", "r", stdin);  
    int l, r;  
    while(scanf("%d%d", &n, &m) != EOF)  
    {  
        sum[0] = 0;dp[0] = 0;  
        for(int i = 1; i <= n; i ++)  
        {  
            scanf("%d", &sum[i]);  
            sum[i] += sum[i - 1];  
        }  
        l = r = 0;  
        d[r ++] = 0;  
        for(int i = 1; i <= n; i ++)  
        {  
            while(l + 1 < r && getUP(d[l + 1], d[l]) <= getDOWN(d[l + 1], d[l]) * sum[i])  
                l ++;  
            dp[i] = getDP(i, d[l]);  
            while(l + 1 < r && getUP(d[r - 1], d[r - 2]) * getDOWN(i, d[r - 1]) >= getDOWN(d[r - 1], d[r - 2]) * getUP(i, d[r - 1]))  
                r --;  
            d[r ++] = i;  
        }  
        printf("%d\n", dp[n]);  
    }  
      
} 