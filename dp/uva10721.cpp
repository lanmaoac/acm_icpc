#include <stdio.h>  
#include <string.h>  
const int N = 55;  
int n, k, m;  
long long dp[N][N];  
  
int main() {  
    while (~scanf("%d%d%d", &n, &k, &m)) {  
    memset(dp, 0, sizeof(dp));  
    dp[0][0] = 1;  
    for (int i = 1; i <= n; i ++) {  
        for (int j = 1; j <= k; j ++) {  
        for (int k = 1; k <= m && k <= i; k ++) {  
            dp[i][j] += dp[i - k][j - 1];  
        }  
        }  
    }  
    printf("%lld\n", dp[n][k]);  
    }  
    return 0;  
} 