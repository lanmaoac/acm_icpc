#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>
#define maxn 2009
#define maxm
#define INF 1e9
#define MOD
using namespace std;
char s[1009][15][15];
int cost[1009][1009];
int dp[1009];
vector<int>G[1009];
struct node
{
    int u,v,w;
    bool operator<(const node &rhs)const
    {
        return w<rhs.w;
    }
}edge[2009*2009*2];
int p[maxn],tot;
int findset(int x)
{
    return p[x]==x?x:p[x]=findset(p[x]);
}
inline void unionset(int x,int y)
{
    p[findset(x)]=findset(y);
}
void dfs(int x,int fa)
{
    if(x!=0)
    {
        printf("%d %d\n",x,fa);
    }
    for(int i=0;i<G[x].size();i++)
    {
        int v=G[x][i];
        if(v!=fa)
            dfs(v,x);
    }
}
int main()
{
    int n,m,k,w;
    scanf("%d%d%d%d",&n,&m,&k,&w);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            scanf("%s",s[i][j]+1);
    for(int i=1;i<=k;i++)
    {
        for(int j=i+1;j<=k;j++)
        {
            for(int x=1;x<=n;x++)
                for(int y=1;y<=m;y++)
                    if(s[i][x][y]!=s[j][x][y])
                        cost[i][j]+=w;
            edge[tot].u=i;
            edge[tot].v=j;
            edge[tot].w=cost[i][j];
            tot++;
        }
    }
    for(int i=1;i<=k;i++)
    {
        edge[tot].u=i;
        edge[tot].v=0;
        edge[tot].w=n*m;
        tot++;
    }
    for(int i=0;i<=k;i++)
        p[i]=i;
    sort(edge,edge+tot);
    int ans=0;
    for(int i=0;i<tot;i++)
    {
        int x=edge[i].u;
        int y=edge[i].v;
        int z=edge[i].w;
        if(findset(x)!=findset(y))
        {
            ans+=z;
            unionset(x,y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    printf("%d\n",ans);
    dfs(0,-1);
}