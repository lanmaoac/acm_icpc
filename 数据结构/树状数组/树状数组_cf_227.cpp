#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
using namespace std;
int pos[1000005];
bool mark[1000005];
int b[1000005];
void add(int idx,int v)
{
   while(idx<=1000005){
    b[idx]+=v;
    idx+=(idx & (-idx));
   }
}
int sum(int idx)
{
  int ans=0;
  while(idx>0){
     ans+=b[idx];
     idx-=(idx & (-idx));
  }
  return ans;
}
int main()
{
  int n,k,a,ans=0;
  set<int> ms;
  set<int>::iterator ite;
  memset(mark,0,sizeof(mark));
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++){
    scanf("%d",&a);
    pos[a]=i;
    add(i,1);
  }
  for(int i=1;i<=k;i++){
    scanf("%d",&a);
    mark[a]=1;
  }
  ms.insert(0);
  ms.insert(n+1);
  for(int i=1;i<=n;i++){
    if(mark[i]){
     ms.insert(pos[i]);
     continue;
  }
  ite = ms.upper_bound(pos[i]);
  int r = *ite - 1;
  int l = *(--ite);
  ans += sum(r) - sum(l);
  add(pos[i], -1);
  
  }
  printf("%d",ans);
  return 0;
}
