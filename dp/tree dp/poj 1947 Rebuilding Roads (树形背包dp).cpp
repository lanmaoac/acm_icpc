#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int >PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 160;
vector<int>adj[MAXN];
int n, p;
int f[MAXN][MAXN], tot[MAXN];
int ans;

int dp(int u) {

    // 计算子树有几个节点
    tot[u] = 1;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        tot[u] += dp(v); 
    }

    // init
    f[u][1] = adj[u].size();
    // dp
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i];
        for (int s = tot[u]; s >= 1; --s) {
            for (int j = 1; j < s && j <= tot[v]; ++j)
                f[u][s] = min(f[u][s], f[u][s-j] + f[v][j] - 1);
        }
    }
    if (tot[u] >= p)
        ans = min(ans, f[u][p] + (u!=1));
    return tot[u];
}

int main(){

    for (int i = 0; i <=n; ++i)
        adj[i].clear();

    scanf("%d %d", &n, &p);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
    }

    memset(f, INF, sizeof(f));
    ans = INF;
    dp(1);

    printf("%d\n", ans);
    return 0;
}