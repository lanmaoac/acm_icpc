#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<string>  
#include<stack>  
#include<queue>  
#include<map>  
#include<set>  
#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<bitset>  
#define FF(i, a, b) for(int i=a; i<b; i++)  
#define FD(i, a, b) for(int i=a; i>=b; i--)  
#define REP(i, n) for(int i=0; i<n; i++)  
#define CLR(a, b) memset(a, b, sizeof(a))  
#define LL long long  
#define PB push_back  
#define debug puts("**debug**")  
using namespace std;  
  
const int maxn = 10010;  
vector<int> G[maxn];  
int n, m, dfs_clock, pre[maxn], low[maxn], cut[maxn];  
struct Ans  
{  
    int id, num;  
    bool operator < (const Ans& rhs) const  
    {  
        return num > rhs.num || (num == rhs.num && id < rhs.id);  
    }  
}ans[maxn];  
  
inline void init()  
{  
    REP(i, n) G[i].clear(); CLR(pre, 0); CLR(cut, 0);dfs_clock = 0;  
}  
  
int dfs(int u, int fa)  
{  
    int lowu = pre[u] = ++dfs_clock;  
    int child = 0, nc = G[u].size();  
    REP(i, nc)  
    {  
        int v = G[u][i];  
        if(!pre[v])  
        {  
            child++;  
            int lowv = dfs(v, u);  
            lowu = min(lowu, lowv);  
            if(low[v] >= pre[u])  
             cut[u]++;  
        }  
        else if(pre[v] < pre[u] && v != fa)  
         lowu = min(lowu, pre[v]);  
    }  
    if(fa < 0) cut[u]--;  
    if(fa < 0 && child == 1) cut[u] = 0;  
    low[u] = lowu;  
    return lowu;  
}  
  
int main()  
{  
    while(scanf("%d%d", &n, &m), n+m)  
    {  
        init();  
        int a, b;  
        while(scanf("%d%d", &a, &b) && a+b != -2)  
        {  
            G[a].PB(b); G[b].PB(a);  
        }  
        REP(i, n) if(!pre[i]) dfs(i, -1);  
        int cnt = 0;  
        REP(i, n) ans[cnt++] = (Ans){i, cut[i]+1};  
        sort(ans, ans+cnt);  
        REP(i, m) printf("%d %d\n", ans[i].id, ans[i].num);  
        puts("");  
    }  
}  