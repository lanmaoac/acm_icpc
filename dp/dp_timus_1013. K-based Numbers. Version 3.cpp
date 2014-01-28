#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <iostream>  
#include <algorithm>  
#include <queue>  
#include <stack>  
#include <math.h>  
using namespace std;  
const int MAX = 3010;  
short dp[1800][MAX];  
short len[1800];  
int main()  
{  
    int n,K;  
    memset(dp,0,sizeof(dp));  
    while( ~scanf("%d%d",&n,&K) )  
    {  
        len[1] = len[2] = 1;  
        dp[1][0] = K-1;  
        dp[2][0] = (K-1)*K;  
        for(int k=3; k<=n; k++)  
        {  
            int mlen = max(len[k-1],len[k-2]);  
            for(int j=0; j<mlen; j++)  
            {  
                dp[k][j] += (K-1)*(dp[k-1][j] + dp[k-2][j]);  
                if( dp[k][j] >= 10 )  
                {  
                    dp[k][j+1] += dp[k][j]/10;  
                    dp[k][j] %= 10;  
                }  
            }  
            int j = mlen;  
            if( dp[k][j] )  
                j++;  
            while( dp[k][j] >= 10 )  
            {  
                dp[k][j+1] += dp[k][j]/10;  
                dp[k][j] %= 10;  
                j++;  
            }  
            len[k] = j;  
        }  
        for(int i=len[n]-1; i>=0; i--)  
            printf("%d",dp[n][i]);  
        printf("/n");  
    }  
return 0;  
} 