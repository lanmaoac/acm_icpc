第一次做树上的分治感觉很蛋疼，主要是树的重心没找好无限t，
最后还是慢慢磨出来了，其实树上的分治和线性区间的处理方法一样，只不过和树链剖分类似，
将树上的操作转化成区间上的操作。也就是怎么将树上的元素之间的联系转化成区间上的元素之间的联系。

//poj 1741

divide and conquer in tree: 
一棵树有N个节点通过有权值的边相互连接，求满足两点之间的距离小于等于K的点对的个数。 
Solution: 
找树的重心(顶点到该点的距离和该点的最大儿子的节点数之差尽可能的小--这样就可以做到路径长度不超过log(n))   ---->    求出以该重心为根节点的点对的个数(注意这里可能出现dis[i] + dis[j] <= K 但是 i 和 j 属于同一条路径,因此要减去这种情况) ---->    采用分治策略对下面的子树进行同样的操作 ---->    合并结果 
Code： 
#define CY 10005 
#define E 2*CY 
typedef int typec; 
  
struct re{ 
    int v, nxt; 
    typec w; 
}e[E]; 
int g[CY], size[CY], limit[CY], ar[CY], dis[CY], MN; 
bool vis[CY]; 
int idx, ID, idy, N, K; 
  
void init() { 
    idx = 0; 
    memset(g, -1, sizeof(g)); 
} 
  
void addedge(int u, int v, typec w) { 
    e[idx].v = v; 
    e[idx].w = w; 
    e[idx].nxt = g[u]; g[u] = idx++; 
} 
  
void get_size(int u, int f) { 
    size[u] = 1; 
    limit[u] = 0; 
    for (int i = g[u]; ~i; i = e[i].nxt) { 
        int v = e[i].v; 
        if (f != v && !vis[v]) { 
            get_size(v, u); 
            size[u] += size[v]; 
            limit[u] = max(limit[u], size[v]); 
        } 
    } 
} 
  
void get_root(int p, int u, int f) { 
    if (size[p] - size[u] > limit[u]) limit[u] = size[p] - size[u]; 
    if (limit[u] < MN) MN = limit[u], ID = u; 
    for (int i = g[u]; ~i; i = e[i].nxt) { 
        int v = e[i].v; 
        if (f != v && !vis[v]) { 
            get_root(p, v, u); 
        } 
    } 
} 
  
void get_dis(int u, int f, typec d) { 
    for (int i = g[u]; ~i; i = e[i].nxt) { 
        int v = e[i].v; 
        if (f != v && !vis[v]) { 
            get_dis(v, u, d + e[i].w); 
        } 
    } 
    dis[idy++] = d; 
} 
  
typec cal(int u, int f, int d) { 
    idy = 0; 
    get_dis(u, f, d); 
    int sum = 0; 
    sort(dis, dis + idy); 
    for (int i = 0, j = idy - 1; i < j; ++i) { 
        while (i < j && dis[i] + dis[j] > K) --j; 
        if (i >= j) break; 
        sum += j - i; 
    } 
    return sum; 
}  
typec get_ans(int u, int f) { 
    get_size(u, f); 
    MN = INF; 
    get_root(f, u, f); 
    int root = ID; 
    typec sum = cal(root, root, 0); 
    vis[root] = true; 
    for (int i = g[root]; ~i; i = e[i].nxt) { 
        int v = e[i].v; 
        if (!vis[v]) { 
            sum -= cal(v, root, e[i].w); 
            sum += get_ans(v, root); 
        } 
    } 
    return sum; 
} 
  
void input(int n) { 
    int u, v, w; 
    for (int i = 1; i < n; ++i) { 
        scanf("%d%d%d", &u, &v, &w); 
        addedge(u, v, w); 
        addedge(v, u, w); 
    } 
} 
  
void solve(int n, int K) { 
    memset(vis, false, sizeof(vis)); 
    typec ans = get_ans(1,1); 
    printf("%d\n", ans); 
} 
  
int main(void) { 
    while (2 == scanf("%d%d", &N, &K)) { 
        if (N == 0 && K == 0) break; 
        init(); 
        input(N); 
        solve(N, K); 
    } 
    return 0; 
} 