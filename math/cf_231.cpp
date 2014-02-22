#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;
int num[1005],n;
int st;int ans;int step;

bool ok(int m)
{
	
	for(int i=0;i<=20001;i++){
		int l=num[n]-m;
	int r=num[n]+m;
	for(int j=n-1;j>=1;j--){
		l-=i;
		r-=i;
		l=max(l,num[j]-m);
		r=min(r,num[j]+m);
	}
	if(l<=r)
	{
		ans=m;
		st=l;
		step=i;
		return 1;
	}
  }
  return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",num+i);
    sort(num+1,num+1+n);
    ans=10000000;
    int l=0;
    int r=20001;
    while(l<r)
    {
    	int mid=(l+r)>>1;
    if(ok(mid))
    	r=mid;
    else l=mid+1;
    }
   printf("%d\n%d %d", ans, st, step);
	return 0;
}