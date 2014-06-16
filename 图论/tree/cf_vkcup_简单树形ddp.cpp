#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
using namespace std;
struct node
{
	int to;
	int next;
}edge[50010*2];
int head[50010];
int dp[50010][510];
int top=0;
int n,kk;
long long int ans=0;
void dfs(int now,int father)
{
	dp[now][0]=1;
	for(int k=head[now];k!=-1;k=edge[k].next){
		int v=edge[k].to;
		if(v==father) continue;
		dfs(v,now);
		for(int j=0;j<kk;j++) ans+=dp[now][j]*dp[v][kk-j-1];
		for(int j=0;j<kk;j++) dp[now][j+1]+=dp[v][j];
	}
}
void add(int from ,int to)
{
   edge[top].to=to;
   edge[top].next=head[from];
   head[from]=top++;
}
int main()
{
	scanf("%d%d",&n,&kk);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
    dfs(1,-1);
    printf("%I64d\n",ans);
	return 0;
}
