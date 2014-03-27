#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <stack>  
#include <queue>  
#include <map>  
#include <set>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <bitset>  
using namespace std;
const int maxn = 20010;
int n,m,x,a,b;
stack<int>s;
int scc_cnt,dfs_time;
vector<int>edge[20010];
vector<int>edge2[20010];
int sum[maxn];
int low[maxn],pre[maxn],sccno[maxn];
int dp[maxn];
void init(){
   for(int i=1;i<=n;i++) edge[i].clear();
   memset(pre,0,sizeof(pre));
   memset(low,0,sizeof(low));
   memset(sccno,0,sizeof(sccno));
   memset(sum,0,sizeof(sum));
   memset(dp,-1,sizeof(dp));
   dfs_time=1;
   scc_cnt=0;
}
void tarjin(int now){
	pre[now]=low[now]=dfs_time++;
	s.push(now);
	for(int i=0;i<edge[now].size();i++){
		int v=edge[now][i];
		if(!pre[v]){
            tarjin(v);
            low[now]=min(low[v],low[now]);

		}
		else if(!sccno[v]){
			 low[now]=min(low[now],pre[v]);
		}
	}
	if(pre[now]==low[now]){
		scc_cnt++;
		for(;;){
			x=s.top();
			s.pop();
			sccno[x]=scc_cnt;
			if(x==now) break;
  		}
	}
}
void find_bcc(int n)
{
     for(int i=1;i<=n;i++) if(!pre[i]) tarjin(i);
}
void build(int n)
{
	for(int i=1;i<=n;i++){
		for(int j=0;j<edge[i].size();j++)
		{
			if(sccno[i]!=sccno[edge[i][j]]) 
				edge2[sccno[i]].push_back(sccno[edge[i][j]]);
		}
		sum[sccno[i]]++;
	}
}
int gao(int a)
{
      if(dp[a]!=-1) return dp[a];
      int ret=0;
      for(int j=0;j<edge2[a].size();j++)
        ret=max(ret,gao(edge2[a][j]));
      return dp[a]=ret+sum[a];   
}
int main()
{ 
    int cas;
    scanf("%d",&cas);
    while(cas--){
     scanf("%d%d",&n,&m);
     init();
     for(int i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
     	edge[a].push_back(b);		
     }
     find_bcc(n);
     build(n); 
     int ans=0;
     for(int i=1;i<=scc_cnt;i++)  
     	ans=max(ans,gao(i));
     cout<<ans<<endl;
    }
	return  0;
}