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
int in[maxn],out[maxn];
int low[maxn],pre[maxn],sccno[maxn];
void init(){
   for(int i=1;i<=n;i++) edge[i].clear();
   memset(pre,0,sizeof(pre));
   memset(low,0,sizeof(low));
   memset(sccno,0,sizeof(sccno));
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
     for(int i=1;i<=scc_cnt;i++) in[i]=out[i]=1;
     for(int i=1;i<=n;i++)																								
     	for(int j=0;j<edge[i].size();j++)
     		if(sccno[i]!=sccno[edge[i][j]])  in[sccno[edge[i][j]]]=out[sccno[i]]=0;
    
     a=0;b=0;
     for(int i=1;i<=scc_cnt;i++){
     	if(in[i]) a++;
        if(out[i]) b++;
    }
        int ans=max(a,b);
        if(ans==1) ans=0;
        printf("%d\n",ans);
    }
	return  0;
}