#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long int64;
const int INF = 0x3f3f3f3f;
const int MAXN = 230;
int n;
bool g[MAXN][MAXN];
int f[MAXN];
struct Node{
    int x, y, h;
}A[MAXN];
bool check(int i, int j) {
    return A[i].x<A[j].x && A[i].y<A[j].y
            || A[i].x<A[j].y && A[i].y<A[j].x;
}
int dfs(int u) {
    if(f[u] != -1) return f[u];
    f[u] = A[u].h;
    for(int i = 0; i < n; ++i) if(g[u][i]){
        f[u] = max(f[u], dfs(i)+A[u].h);
    }
    return f[u];
}
int main(){

    int cas = 1;
    while (~scanf("%d", &n) && n) {
    
        for(int i = 0; i < n; ++i) {
            scanf("%d%d%d", &A[i].x, &A[i].y, &A[i].h);
            A[n+i].x=A[i].x;   A[n+i].y=A[i].h;   A[n+i].h=A[i].y;
            A[2*n+i].x=A[i].y; A[2*n+i].y=A[i].h; A[2*n+i].h=A[i].x;
        }

        n *= 3;

        memset(g, 0, sizeof(g));
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j < n; ++j) {
                g[i][j] = check(i, j);
                g[j][i] = check(j, i);
            }

        int ans = 0;
        memset(f, -1, sizeof(f));
        for(int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i)); 
        }
        printf("Case %d: maximum height = %d\n", cas++, ans);
    }

    return 0;
}