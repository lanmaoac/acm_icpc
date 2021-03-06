#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
const int  N = 100005;
struct node
{
  int val;
  int id;
}a[N];
vector<int >edge[N*2];
int in[N*2],n,m,cnt;
int ans[N],tot=0; 
queue<int> que;
void add(int u,int v)
{
  in[v]++;
  edge[u].push_back(v);
}
bool cmp(node a,node b)
{
  return a.val<b.val;
}
int main()
{ 
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
      scanf("%d",&a[j].val);
      a[j].id=j;
     } 
     sort(a,a+m,cmp);
     for(int j=0;j<m;j++){
        if(a[j].val==-1) continue;
        if(!j||a[j].val!=a[j-1].val) cnt++;
        add(a[j].id,m+cnt+1);
        add(m+cnt,a[j].id);
      }
     cnt++;
   }
   for(int i=0;i<m+cnt;i++)
      if(!in[i]) que.push(i);
   while(!que.empty()){  
        int u=que.front();que.pop();  
        if(u<m)  
            ans[tot++]=u;  
        for(int i=0;i<edge[u].size();i++){  
            int v=edge[u][i];  
            in[v]--;  
            if(!in[v])  
                que.push(v);  
        }  
    }  
    if(tot<m) puts("-1");  
    else{  
        for(int i=0;i<m;i++)  
            cout<<ans[i]+1<<(i==m-1?"\n":" ");  
    }  

  return 0;
}
