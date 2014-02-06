#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iostream>
using namespace std;
//扫描法求最大子矩阵
const int N= 1010;
int mat[N][N],lef[N][N],rig[N][N],up[N][N];
int main()
{
  int cas,m,n;
  scanf("%d",&cas);
  while(cas--){
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        char ch=getchar();
        while(ch!='F'&&ch!='R') ch=getchar();
          mat[i][j]= ch== 'F' ? 0 : 1 ;
      }
   int ans=0;
   for(int i=0;i<n;i++){
      int lo=-1,ro=n;
      for(int j=0;j<m;j++){
          if(mat[i][j]==1) {up[i][j]=0;lef[i][j]=0;lo=j;}
          else{
            up[i][j]= i==0?1:up[i-1][j]+1;
            lef[i][j]= i==0?lo+1:max(lef[i-1][j],lo+1);
          }
      }
      for(int j=n-1;j>=0;j--){
        if(mat[i][j]==1) {rig[i][j]=n;ro=j;}
        else {
           rig[i][j]=i==0?ro-1:min(rig[i-1][j],ro-1);
           ans=max(ans,up[i][j]*(rig[i][j]-lef[i][j]+1));
        }
      }
    }
    printf("%d\n",ans*3);
 }
  return 0;
}
