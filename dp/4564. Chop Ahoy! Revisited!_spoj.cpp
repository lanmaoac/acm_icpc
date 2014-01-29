#include<stdio.h>
#include<string.h>
#define MAXD 30
#define MAXS 250
int N, S, A[MAXD], f[MAXD][MAXS];
char b[MAXD];
void init()
{
    int i;
    N = strlen(b + 1);
    S = N * 9;
    A[0] = 0;
    for(i = 1; i <= N; i ++)
        A[i] = A[i - 1] + b[i] - '0';
}
void solve()
{
    int i, j, k, ans = 0;
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for(i = 1; i <= N; i ++)
        for(j = 0; j < i; j ++)
            for(k = 0; k <= A[i] - A[j]; k ++)
                f[i][A[i] - A[j]] += f[j][k];
    for(i = 0; i <= S; i ++)
        ans += f[N][i];
    printf("%d\n", ans);
}
int main()
{
    int t = 0;
    while(scanf("%s", b + 1) == 1, b[1] != 'b')
    {
        init();
        printf("%d. ", ++ t);
        solve();
    }
    return 0;    
}