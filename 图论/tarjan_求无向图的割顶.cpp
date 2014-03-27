#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <vector>
using namespace std;
const int  maxn = 150;
int n,ans,dfs_time;
vector <int>edge[maxn];
int pre[maxn],low[maxn];
int cut[maxn];
void init(){
	for(int i=1;i<=n;i++)
		edge[i].clear();
	memset(pre,-1,sizeof(pre));
	memset(low,0,sizeof(low));
	dfs_time=1;
	ans=0;
}
void add(int from,int to){
	edge[from].push_back(to);
	edge[to].push_back(from);
}
void tarjan(int now,int fa){
     pre[now]=low[now]=dfs_time++;
     int child=0;
     for(int i=0;i<edge[now].size();i++){
     	int v=edge[v]][i];
     	if(pre[v]==-1){
     		 child++;
             tarjan(v,now);
             if(low[u] > low[v])low[u] = low[v];  
             if(low[v] >= pre[u]) cut[u] = 1;  
        }
     	else if(low[now]>pre[v]) low[now]=pre[v]; 
     }
     if(fa==-1 && child ==1) cut[now]=0;
     if(cut[now]) ans++;
}	
int main()
{ 
    while(scanf("%d",&n)!=EOF){
    	init();
    	int a,b;
    	while(scanf("%d",&u) && u){
    		while(getchar()!='\n'){
    			scanf("%d",&v);
    			add(u,v);
    		}
    	}
    	tarjan(1,-1);
    	printf("%d\n",ans);
    }
	return 0;
}
