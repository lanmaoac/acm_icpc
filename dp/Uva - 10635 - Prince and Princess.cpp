#include <cstdio>  
#include <algorithm>  
#include <cstring>  
  
using namespace std;  
  
const int maxn = 250 + 10;  
const int INF = 1000000000;  
  
int num[maxn*maxn], princess[maxn*maxn], g[maxn*maxn], d[maxn*maxn];  
  
int main()  
{  
    int t, n, p, q, i, temp;  
    scanf("%d", &t);  
    for(int kase = 1; kase <= t; kase++)  
    {  
        scanf("%d%d%d", &n, &p, &q);  
        memset(num, 0, sizeof(0));  
        for(i = 1; i <= p+1; i++)  
        {  
            scanf("%d", &temp);  
            num[temp] = i;  
        }  
        int m = 1;  
        for(i = 1; i <= q+1; i++)  
        {  
            scanf("%d", &temp);  
            if(num[temp]) princess[m++] = num[temp];  
        }  
        for(i = 1; i < m; i++) g[i] = INF;  
        int ret = -1;  
        for(i = 1; i < m; i++)  
        {  
            int k = lower_bound(g+1, g+m, princess[i]) - g;  
            d[i] = k;  
            g[k] = princess[i];  
            ret = max(ret, d[i]);  
        }  
        printf("Case %d: %d\n", kase, ret);  
    }  
    return 0;  
}