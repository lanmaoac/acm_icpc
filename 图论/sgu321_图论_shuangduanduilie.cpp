#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>

#include <deque>

const int maxn = 200007;
typedef std::pair<bool,std::pair<int,int> >node;
node edge[maxn];
std::vector<int>adj[maxn];
int top=0;
int cnt=0;int tot=0;
int len=0;
int ans[maxn];
std::deque<int>path;
void add(int from,int to,int w)
{
	edge[top++]=std::make_pair(w,std::make_pair(from,to));
	edge[top++]=std::make_pair(w,std::make_pair(to,from));
	adj[from].push_back(top-2);
	adj[to].push_back(top-1);
}
void dfs(int now,int father)
{
  if(2*cnt<len){
  	ans[tot++]=path.front();
  	edge[path.front()].first=true;
  	path.pop_front();
  	++cnt;
  }
  for(int i=0;i<adj[now].size();i++){
  	int e=adj[now][i];
  	int v=edge[e].second.second;
  	if(v==father) continue;
  	if(!edge[e].first) path.push_back(e);
  	cnt+=edge[e].first?1:0;
  	len+=1;
  	dfs(v,now);
  	len-=1;
  	if(!edge[e].first) path.pop_back();
  	cnt-=cnt+=edge[e].first?1:0;
   }
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++){
		int a,b,w;char s[500];
		scanf("%d%d%s",&a,&b,s);
		if(s[0]=='a')
			w=0,scanf("%s",s);
		else w=1;
		add(a,b,w);
   }
    dfs(1,-1);
    printf("%d\n",tot);
	if (tot>0) printf("%d",ans[0]);
	for (int i=1;i<tot;++i) printf(" %d",ans[i]);
	putchar('\n');
	return 0;


}
