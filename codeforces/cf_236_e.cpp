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
#include <stack>
using namespace std;
vector<int >edge[2005];
int pre[2005],low[2005],dfs_time,x;
int scc_cnt;int sccno[2005];
stack<int>s;
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
	int n;
	dfs_time=1;
	scc_cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
	{

      scanf("%d",&x);
      if(x>0) edge[i].push_back(j);
	}
    find_bcc(n);
      if(scc_cnt==1)
   {
   	printf("YES");
   }
   else printf("NO");
	return 0;
}
