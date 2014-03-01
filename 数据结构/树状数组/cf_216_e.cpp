#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
vector <int>q[1000015];
vector <int>ed[1000015];
int ans[1000015]={0};
int bit[1000015*2]={0};
int  sum(int x)
{
	int  sum=0;
	while(x>0){
		sum+=bit[x];
		x-=(x & (-x));
	}
	return sum;
}
void add(int x,int k)
{
	while(x<=1000015*2){
		bit[x]+=k;
		x+=(x & (-x));
	}
}
int main()
{
   int n,m,cnt,x,y,id,a,b;
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;i++){
   	 scanf("%d%d",&a,&b);
   	 ed[a].push_back(b);
     add(b,1);
   }
   for(int i=1;i<=m;i++){
     scanf("%d%d",&cnt,&x);
     q[0].push_back(x-1);
     q[0].push_back(i);
     x++;
     for(int j=1;j<cnt;j++){
     	 scanf("%d",&y);
     	 q[x].push_back(y-1);
     	 q[x].push_back(i);
         y++;
         x=y;
     }
     q[x].push_back(1000010);
     q[x].push_back(i);
   }
   printf("sdfsdfas");
   for(int i=0;i<=1000010;i++){
      for(int j=0;j<q[i].size();j+=2){
         y=q[x][j];id=q[x][j+1];
         ans[id]+=sum(y);
      }
      for(int j=0;j<ed[i].size();j++)
      	add(ed[i][j],-1);
   }
   for(int i=1;i<=m;i++)
   	cout<<n-ans[i]<<endl;

   return 0;

}
