#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <vector>
using namespace std;
vector<int> adj[1010];
int vis[1010][2];
int dp[1010][2];
int n,m;
int gao(int i,int j,int f)
{
  if(vis[i][j]) return dp[i][j];
  vis[i][j]= 1;
  int &ans=dp[i][j];
  ans=2000;
  for(int k=0;k<adj[i].size();k++)
  	if(adj[i][k]!=f) ans+=gao(adj[i][k],1,i);
  if(!j && f>=0) ans++;
  if(j || f<0){
  	int sum=0;
  	for(int k=0;k<adj[i].size();k++)
  		if(adj[i][k]!=f) sum+=gao(adj[i][k],0,i);
  	if(f>=0) sum++;
  	ans=min(ans,sum);
  }
  return ans;
}
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--){
    	scanf("%d%d",&n,&m);
    	for(int i=0;i<n;i++) adj[i].clear();
    	for(int i=0;i<m;i++) {
    		scanf("%d%d",&a,&b);
    		adj[a].push_back(b);
    		adj[b].push_back(a);
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<n;i++){
        	if(!vis[i][0])
        		ans+=gao(i,0,-1);
        }
        printf("%d %d %d\n",ans/2000,m-ans%2000,ans%2000);
     }
	return 0;
}
