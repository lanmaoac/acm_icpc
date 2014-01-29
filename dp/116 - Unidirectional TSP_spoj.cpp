#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#define min(a,b) (((a) < (b)) ? (a) : (b)) 
int map[15][105]; int dp[15][105], path[15][105];
 int n, m; 
 int main() 
 { 
  while (scanf("%d %d", &n, &m) != EOF) 
    { 
    for (int i = 0; i < n; ++i) 
      for (int j = 0; j < m; ++j)
         scanf("%d", &map[i][j]); 
     memset(dp, 0, sizeof(dp)); 
     memset(path, 0,sizeof(path));
     for (int j = m - 1; j >= 0; --j)
      { 
          for (int i = 0; i < n; ++i) 
          { 
            int a = dp[(i-1+n)%n][j+1]; 
            int b = dp[i][j+1]; 
            int c = dp[(i+1)%n][j+1]; 
            int mm; 
            if (a > b) mm = min(b, c);
            else mm = min(a, c); 
            dp[i][j] = map[i][j] + mm;
            path[i][j] = 1e9; 
            if (mm == a) path[i][j] = (i - 1 + n) % n; 
            if (mm == b) path[i][j] = min(path[i][j], i); 
            if (mm == c) path[i][j] = min(path[i][j], (i + 1) % n); 
          }
      }
       int ans = 1e9; int id; 
       for(int i = 0; i < n; ++i) 
         if(ans > dp[i][0]) ans = dp[i][0], id = i;
           printf("%d", id + 1);
      id = path[id][0]; 
      for (int j = 1; j < m; ++j)
        {
          printf(" %d", id + 1); 
          id = path[id][j]; 
        } 
      printf("\n%d\n", ans);
 }
return 0; 
}