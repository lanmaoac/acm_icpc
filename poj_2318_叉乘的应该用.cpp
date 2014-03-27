#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int lown[50010],upn[50010];
int n,m,x,y,up,low,Left,Right;
int box[50010];
bool isleft(int x,int y,int  k)
{
	return (upn[k]-lown[k])*(y-low)>(x-lown[k])*(up-low);
}
int gao(int x,int  y)
{
	int l=0;
	int r=n+1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(isleft(x,y,mid)) r=mid;
		else  l=mid+1;
	}
	return l-1;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(box,0,sizeof(box));
    	scanf("%d%d%d%d%d",&m,&Left,&up,&Right,&low);
    	for(int i=1;i<=n;i++)
    		scanf("%d %d",upn+i,lown+i);
    	lown[0]=upn[0]=Left;
    	upn[n+1]=lown[n+1]=Right;
    	for(int i=1;i<=m;i++){
    		scanf("%d%d",&x,&y);
    		int pos=gao(x,y);
    		box[pos]++;
    	}
    	for(int i=0;i<=n;i++){
    		printf("%d: %d",i,box[i]);
    	}
    }
	return 0;
}
