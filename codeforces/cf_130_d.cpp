#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
long long int n,m;
long long int  f[205][205],g[205][205];
long long map[205][205];
//long long  max(long long a,long long b)
//{
     //if(a>=b) return a;
    // return b;
//}
struct node
{
    int to;
    int next;
}edge[80008];
int head[505];
int top=0;
void add(int from,int to)
{
    edge[top].to=to;
    edge[top].next=head[from];
    head[from]=top++;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    memset(head,-1,sizeof(head));
    memset(map,0,sizeof(map));
    for(int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        map[a][b]=1;
        map[b][a]=1;
        add(a,b);
        add(b,a);
        }
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        if(map[i][k])
            for(int j=1;j<=n;j++)
                if(map[k][j])
                    if(!map[i][j] || map[i][j]>map[i][k]+map[k][j])
                        map[i][j]=map[i][k]+map[k][j];
    int now=map[1][n];
    f[1][0]=1;
    for(int i=0;i<now;i++)
        for(int j=1;j<=n;j++)
        for(int  k=head[j];k!=-1;k=edge[k].next)
        {
            f[edge[k].to][i+1]+=f[j][i];
        }
    g[n][0]=1;
    for(int i=0;i<now;i++)
        for(int j=1;j<=n;j++)
        for(int  k=head[j];k!=-1;k=edge[k].next)
        {
            g[edge[k].to][i+1]+=g[j][i];
        }
    long long int ans=-10;
    for(int i=2;i<n;i++)
        if(map[1][i]+map[i][n]==now)
        {
         ans=max(ans,f[i][map[1][i]]*g[i][map[i][n]]);
        }
  ans*=2;
  ans=max(ans,f[n][now]);
  double res;
  res=(double)ans/(double)f[n][now];
  printf("%.12lf",res);
 return 0;
}
