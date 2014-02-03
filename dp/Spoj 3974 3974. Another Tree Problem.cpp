#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=100010;
const int MOD=1000000007;
struct node{int to,next;long long w;}edges[MAXN*2];
int box[MAXN],size,n;
long long ans,sum[MAXN];
void add(int from,int to,long long w)
{
    edges[size].to=to;
    edges[size].w=w;
    edges[size].next=box[from];
    box[from]=size++;
}
void init()
{
    int a,b,c;
    scanf("%d",&n);
    memset(box,-1,sizeof(box));
    memset(sum,0,sizeof(sum));
    size=ans=0;
    for(int i=0;i<n-1;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);add(b,a,c);
    }
}
void dfs(int x,int father)
{
    for(int i=box[x];i!=-1;i=edges[i].next)
    {
        int ne=edges[i].to;
        if(ne==father)continue;
        dfs(ne,x);
        ans=(ans+sum[x]*edges[i].w%MOD*(sum[ne]+1))%MOD;
        sum[x]=(sum[x]+edges[i].w*(sum[ne]+1))%MOD;
    }
    ans=(ans+sum[x])%MOD;
}
int main()
{
//    freopen("in.txt","r",stdin);
    init();
    dfs(1,-1);
    cout<<ans<<endl;
    return 0;
}