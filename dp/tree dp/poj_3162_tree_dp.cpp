#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct node
{
    int next;
    int lenth;
    int weight;
    int to;
} edge[2000010];
struct node2//定义线段树区间结构
{
    int l,r,maxx,minn;//l,r分别代表左右端点。maxx，minn分别为最大值。最小值
                     //en标记[l,r]链子价值是否相同
} sbt[4000010];//4倍就合适了。
int n,m,cnt,head[1000010],vis[1000010],dp[1000010];
int ma(int a,int b){ return a>b?a:b; }
int mi(int a,int b){ return a<b?a:b; }
void btree(int l,int r,int k)//以[l,r]建立线段树.k为结点号下同
{
    int mid,ls,rs;//mid记录线段中点。ls,rs左右儿子
    sbt[k].l=l;
    sbt[k].r=r;
    if(l==r)//如果到了叶子结点。
    {
        sbt[k].maxx=sbt[k].minn=dp[l];
        return;
    }
    ls=k<<1;//计算左右儿子标号
    rs=k<<1|1;
    mid=(l+r)>>1;
    btree(l,mid,ls);//递归构造线段树
    btree(mid+1,r,rs);
    sbt[k].maxx=ma(sbt[ls].maxx,sbt[rs].maxx);
    sbt[k].minn=mi(sbt[ls].minn,sbt[rs].minn);
}
int qu_max(int l,int r,int k)//询问[l,r]
{
    int mid,ls,rs;
    if(sbt[k].l==l&&sbt[k].r==r)//如果被询问区间刚好匹配
       return sbt[k].maxx;
    ls=k<<1;
    rs=k<<1|1;
    mid=(sbt[k].l+sbt[k].r)>>1;
    if(l>mid)//递归询问
        return qu_max(l,r,rs);
    else if(r<=mid)
        return qu_max(l,r,ls);
    else
        return ma(qu_max(l,mid,ls),qu_max(mid+1,r,rs));
}
int qu_min(int l,int r,int k)//询问[l,r]间的最大值
{
    int mid,ls,rs;

    if(sbt[k].l==l&&sbt[k].r==r)//如果被询问区间刚好匹配
       return sbt[k].minn;
    ls=k<<1;
    rs=k<<1|1;
    mid=(sbt[k].l+sbt[k].r)>>1;
    if(l>mid)//递归询问
        return qu_min(l,r,rs);
    else if(r<=mid)
        return qu_min(l,r,ls);
    else
        return mi(qu_min(l,mid,ls),qu_min(mid+1,r,rs));
}
void adde(int fa,int son,int w)
{
    edge[cnt].to=son;
    edge[cnt].next=head[fa];
    edge[cnt].weight=w;
    head[fa]=cnt++;
}
void dfs(int fa)
{
    vis[fa]=1;
    int p=head[fa];
    while(p!=-1)
    {
        if(vis[edge[p].to])
        {
            p=edge[p].next;
            continue;
        }
        dfs(edge[p].to);
        dp[fa]=ma(dp[fa],dp[edge[p].to]+edge[p].weight);
        edge[p].lenth=dp[edge[p].to]+edge[p].weight;
        p=edge[p].next;
    }
}
void solve(int fa,int son)
{
    if(vis[son])
        return;
    int maxx=0,p;
    vis[son]=1;
    p=head[fa];
    while(p!=-1)
    {
        if(edge[p].to!=son)
           maxx=ma(maxx,edge[p].lenth);
        p=edge[p].next;
    }
    p=head[son];
    while(p!=-1)
    {
        if(edge[p].to==fa)
           {
               edge[p].lenth=maxx+edge[p].weight;
               break;
           }
        p=edge[p].next;
    }
    p=head[son];
    while(p!=-1)
    {
        dp[son]=ma(dp[son],edge[p].lenth);
        solve(son,edge[p].to);
        p=edge[p].next;
    }
}
int main()
{
    int i,f,l,r,w,p,mx,mn,ans;

    while(~scanf("%d%d",&n,&m))
    {
        memset(head,-1,sizeof head);
        memset(dp,0,sizeof dp);
        memset(vis,0,sizeof vis);
        cnt=0;
        ans=0;
        for(i=2;i<=n;i++)
        {
            scanf("%d%d",&f,&w);
            adde(f,i,w);
            adde(i,f,w);
        }
        getchar();
        dfs(1);
        memset(vis,0,sizeof vis);
        p=head[1];
        while(p!=-1)
        {
            solve(1,edge[p].to);
            p=edge[p].next;
        }
        btree(1,n,1);
        l=r=1;
        while(r<=n)
        {
            mx=qu_max(l,r,1);
            mn=qu_min(l,r,1);
            if(mx-mn<=m)
            {
                ans=ma(ans,r-l+1);
                r++;
            }
            else
                l++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
