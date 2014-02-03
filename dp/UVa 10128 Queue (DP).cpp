#include<cstdio>
#include<cstring>

long long f[20][20][20];

void prepare()///组合太麻烦，果断递推之
{
  int i, j, k;
  f[1][1][1] = 1;
  for (i = 2; i <= 13; ++i)
    for (j = 1; j <= i; ++j)
      for (k = 1; k <= i; ++k)
        f[i][j][k] = f[i - 1][j - 1][k] + f[i - 1][j][k - 1] + (i - 2) * f[i - 1][j][k];
}

int main()
{
  prepare();
  int t, N, P, Q;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d%d%d", &N, &P, &Q);
    printf("%lld\n", f[N][P][Q]);
  }
  return 0;
}