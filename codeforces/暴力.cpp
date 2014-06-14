#include <iostream>
#include <cstring>
#include <memory>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <vector>
int n,x;
int t[2005];
int h[2005];
int m[2005];
bool used[2005];
int main()
{ 
  scanf("%d%d",&n,&x);
  for(int i=1;i<=n;i++)
  scanf("%d%d%d",t+i,h+i,m+i);
int ans=0;
  for(int now=0;now<=1;now++)
  { 
    int nowh=x;
    int tnow=now;
    int cntans=0;
    while(1)
    { 
      mnow=-1;
      ponow=-1;
      for(int i=1;i<=n;i++)
      if(t[i]==tnow&&h[i]<=nowh&&m[i]>nowm&&!used[i])
         {
           mnow=m[i];
           posnow=i; 
         }
        if(posnow==-1) break;
        nowh+=x;
        used[pos]=1;
        nowh+=m[pos];
        tnow^=1; 
    }
    ans=max(ans,cntans);
  }
  printf("%d",ans);
  return 0;
}