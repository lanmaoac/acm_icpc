#include<cstdio>
 2 #include<cstring>
 3 #include<vector>
 4 #include<algorithm>
 5 using namespace std;
 6 
 7 const int maxn = 1000 + 10;
 8 vector<int> gr[maxn], nodes[maxn];
 9 int n, s, k, fa[maxn];
10 bool covered[maxn];
11 
12 // 无根树转有根树，计算fa数组，根据深度把叶子结点插入nodes表里
13 void dfs(int u, int f, int d) {
14   fa[u] = f;
15   int nc = gr[u].size();
16   if(nc == 1 && d > k) nodes[d].push_back(u);
17   for(int i = 0; i < nc; i++) {
18     int v = gr[u][i];
19     if(v != f) dfs(v, u, d+1);
20   }
21 }
22 
23 void dfs2(int u, int f, int d) {
24   covered[u] = true;
25   int nc = gr[u].size();
26   for(int i = 0; i < nc; i++) {
27     int v = gr[u][i];
28     if(v != f && d < k) dfs2(v, u, d+1); // 只覆盖到新服务器距离不超过k的结点
29   }
30 }
31 
32 int solve() {
33   int ans = 0;
34   memset(covered, 0, sizeof(covered));
35   for(int d = n-1; d > k; d--) 
36     for(int i = 0; i < nodes[d].size(); i++) {
37       int u = nodes[d][i];
38       if(covered[u]) continue; // 不考虑已覆盖的结点
39 
40       int v = u;
41       for(int j = 0; j < k; j++) v = fa[v]; // v是u的k级祖先
42       dfs2(v, -1, 0); // 在结点v放服务器
43       ans++;
44     }
45   return ans;
46 }
47 
48 int main() {
49   int T;
50   scanf("%d", &T);
51   while(T--) {
52     scanf("%d%d%d", &n, &s, &k);
53     for(int i = 1; i <= n; i++) { gr[i].clear(); nodes[i].clear(); }
54     for(int i = 0; i < n-1; i++) {
55       int a, b;
56       scanf("%d%d", &a, &b);
57       gr[a].push_back(b);
58       gr[b].push_back(a);
59     }
60     dfs(s, -1, 0);
61     printf("%d\n", solve());
62   }
63   return 0;
64 }