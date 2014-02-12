#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int INF = 1000006;
int n,m;
struct node
{
    int to;
    int next;
    int w;
}edge[1005*2];
int head[1005],top;
int dp[1005];
int mid;
void init(){
    memset(head,-1,sizeof(head));
    top=0;
}
void add(int from,int to,int w){
   edge[top].to=to;
   edge[top].next=head[from];
   edge[top].w=w;
   head[from]=top++;
}
void gao(int now,int father){
    if(edge[head[now]].to==father)
    {
        dp[now]=INF;return;
    }
    dp[now]=0;
    for(int k=head[now];k!=-1;k=edge[k].next){
        int v=edge[k].to;
        int w=edge[k].w;
        if(v==father) continue;
        gao(v,now);
        if(w>mid)
            dp[now]+=dp[v];
        else
            dp[now]+=min(w,dp[v]);
   }
}
int main()
{
   while(scanf("%d%d",&n,&m)&&n+m){
    init();
    for(int i=1;i<=n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
        add(b,a,c);
    }
   int l=0;int r=INF;
   int ans=INF;
   while(l<=r){
    mid=(l+r)/2;
    gao(1,-1);
    if(dp[1]<=m){
        ans=min(ans,mid);
        r=mid-1;
    }
    else l=mid+1;
   }
   if(ans==INF) ans=-1;
   cout<<ans<<endl;
   }
   return 0;
}
