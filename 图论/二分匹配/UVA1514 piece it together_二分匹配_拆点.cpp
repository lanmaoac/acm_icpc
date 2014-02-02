#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
const int N= 250005;
char cap[505][505];
int id[505][505],top=0,n,m;
int le[N],vis[N],black,white;
struct node
{
  int to;
  int next;
}edge[N*4];
int head[N];
void add(int from,int to)
{
  edge[top].to=to;
  edge[top].next=head[from];
  head[from]=top++;
}
int match(int n){
    for(int i = head[n]; i != -1; i = edge[i].next){
        int j = edge[i].to;
        if(!vis[j]){
            vis[j] = true;
            if(le[j] == -1 || match(le[j])){
                le[j] = n;
                return 1;
            }
        }
    }
    return 0;
}

int hungary(){
    int sum = 0;
    memset(le, -1, sizeof(le));
    for(int i = 0; i < black; i++){
        memset(vis, 0, sizeof(vis));
        if(match(i)) sum++;
        else break;
    }
    return sum;
}

int main()
{
  int cas;
  scanf("%d",&cas);
  while(cas--){
   scanf("%d%d",&n,&m);
   black=0;white=0;
   for(int i=0;i<n;i++){
    scanf("%s",cap[i]);
      for(int j=0;j<m;j++){
        if(cap[i][j]=='B')
          id[i][j]=black,black++;
        if(cap[i][j]=='W')
          id[i][j]=white,white++;
      }
    }
    top=0;
  if(black == 0 && white == 0){
    printf("YES\n");

    continue;
  }
  if(black*2 != white){
    printf("NO\n");
    continue;
  }
  memset(head,-1,sizeof(head));
  for(int i=0;i<n;i++)
  for(int j=0;j<m;j++)
    if(cap[i][j]=='B'){
        if(i>0&&cap[i-1][j]=='W')
           add(id[i][j],id[i-1][j]);
        if(i<n-1&&cap[i+1][j]=='W')
           add(id[i][j],id[i+1][j]);
        if(j>0&&cap[i][j-1]=='W')
           add(id[i][j]+black,id[i][j-1]);
        if(j<m-1&&cap[i][j+1]=='W')
           add(id[i][j]+black,id[i][j+1]);
  }
  black+=black;
  if(hungary()==white) printf("YES\n");
  else printf("NO\n");
}
  return 0;
}
