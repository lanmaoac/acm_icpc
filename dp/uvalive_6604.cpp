#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,k,x,y;
int num[20005];
int sum[20005*4];
void push_up(int root)
{
	sum[root]=sum[2*root]+sum[2*root+1];
}
void build(int root,int l,int r)
{
	if(l==r) {sum[root]=0;return ;}
	int mid=(l+r)>>1;
	build(2*root,l,mid);
	build(2*root+1,mid+1,r);
	push_up(root);
}
int qurry(int root,int  l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return sum[root];
	int mid=(l+r)>>1;
	int ans=0;
	if(ql<=mid) ans+=qurry(2*root,l,mid,ql,qr);
	if(mid+1<=qr) ans+=qurry(2*root+1,mid+1,r,ql,qr);
	return ans;
}
void update(int root,int pos,int l,int r)
{
     if(l==r) {sum[root]++;return;}
     int mid=(l+r)>>1;
     if(pos<=mid)
     	update(2*root,pos,l,mid);
     else
     	update(2*root+1,pos,mid+1,r);
     push_up(root);
}
int gao(int i)
{
	if(i>=num[i]*k+1&&i<=(num[i]+1)*k)  return 0;
	else return min(abs(i-num[i]*k-1),abs(i-(num[i]+1)*k));
}
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
        	scanf("%d",num+i);
        	num[i]=(num[i]-1)/k;
        }
        build(1,0,20005);
        x=0;y=0;
        for(int i=1;i<=n;i++){
        	x+=qurry(1,0,20005,num[i]+1,20005);
            y=max(y,gao(i));
            update(1,num[i],0,20005);
        }
        printf("Case %d: %d\n",cas++,x-y);
	}
	return 0;
}
