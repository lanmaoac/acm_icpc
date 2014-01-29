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

const int MAXN = 55;
int l, n;
int c[MAXN];
int f[MAXN][MAXN];


int main(){

    while (~scanf("%d %d", &l, &n) && l) {
    
        for (int i = 0; i < n; ++i)
            scanf("%d", &c[i]);

        c[n] = l;
    
        for (int d = 2; d <= n+1; ++d) {
            for (int l = 0; l + d -1 <= n; ++l) {
                int r = l + d - 1;
                int& ans = f[l][r] = INF;
                for (int k = l; k < r; ++k) {
                    ans = min(ans, f[l][k]+f[k+1][r]+c[r]-c[l-1]);
                }
            } 
        }

        printf("The minimum cutting is %d.\n", f[0][n]);
    }
    return 0;
}