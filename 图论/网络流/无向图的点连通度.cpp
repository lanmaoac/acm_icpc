#include <stdio.h>
#include <string.h>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm> 
  
#define MAXV 110  
#define INF 1<<29  
#define min(a,b) (a>b?b:a)  
using namespace std;  
int map[MAXV][MAXV],flow[MAXV][MAXV];  
int parent[MAXV];           //用于bfs寻找路径  
  
int bfs(int n,int start,int end){  
    int a[MAXV],i,v;  
    queue <int>q;  
  
    memset(a,0,sizeof(a));              //记录增广路最小流量，而且又可以当做广搜的标记数组  
    memset(parent,-1,sizeof(parent));       //记录下这条增广路，以便增流  
      
    q.push(start);  
    a[start]=INF;  
    while(!q.empty()){  
        v=q.front();q.pop();  
        for(i=0;i<n;i++){  
            if(!a[i] && map[v][i]>flow[v][i]){       //如果这是一条允许弧就记录下来  
                q.push(i);  
                parent[i]=v;  
                a[i]=min(a[v],map[v][i]-flow[v][i]);  
            }  
        }  
        if(v==end) break;               //找到增广路退出  
    }  
    return a[end];  
}  
  
int EdmondsKarp(int n,int sp,int fp){  
    int i,tmp;  
    int maxflow=0;  
    memset(flow,0,sizeof(flow));  
    while(tmp=bfs(n,sp,fp)){  
        for(i=fp;i!=sp;i=parent[i]){                //根据父亲数组更新流量  
            flow[i][parent[i]]-=tmp;            //更新反向流  
            flow[parent[i]][i]+=tmp;            //更新正向流  
        }  
        maxflow+=tmp;  
    }  
    return maxflow;  
}  
  
int main(){  
    int i,a,b;  
    int n,m;  
    while(~scanf("%d %d",&n,&m)){  
        memset(map,0,sizeof(map));  
        for(i=0;i<n;i++) map[i][i+n]=1;  
        for(i=0;i<m;i++){  
            scanf(" (%d,%d)",&a,&b);  
            map[a+n][b]=map[b+n][a]=INF;  
        }  
          
        int ans=INF;  
        for(i=1;i<n;i++){  
            ans=min(ans,EdmondsKarp(n*2,n,i));  
        }  
          
        if(ans==INF) printf("%d\n",n);  
        else printf("%d\n",ans);  
    }  
    return 0;  
}  