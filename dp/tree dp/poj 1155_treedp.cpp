#include<cstdio>
#include<cstring>
#define max(a,b) a>b?a:b
const int INF = 1000000000;
const int maxn = 3010;
int head[maxn],dp[maxn][maxn],n,m;
int num[maxn];
struct EDGE{
    int v,w,next;
}edge[maxn];
int  tot;
void add_edge(int s,int t,int w){
    edge[tot].v=t;
    edge[tot].w=w;
    edge[tot].next=head[s];
    head[s]=tot++;
}
void dfs(int u){
    int i,j,k,tmp[maxn];
    for(i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        dfs(v);
        for(j=0;j<=num[u];j++)
            tmp[j]=dp[u][j];
         for(j = 0; j <= num[u]; j ++)
            for(k = 1; k <= num[v]; k ++)
                dp[u][j+k] = max(dp[u][j+k], tmp[j]+dp[v][k]-edge[i].w);
        num[u] += num[v];//利用回溯，自底向上的进行DP
    }
}
int main(){
    int i,j,k,a,c;
    tot=0;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dp[i][j]=-INF;
    for(i=1;i<=n-m;i++){
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%d%d",&a,&c);
            add_edge(i,a,c);
        }
    }
    memset(num,0,sizeof(num));
    for(i=n-m+1;i<=n;i++){
        num[i]=1;
        scanf("%d",&dp[i][1]);
    }
    dfs(1);
    for(i=m;i>=0;i--){
        if(dp[1][i]>=0){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}