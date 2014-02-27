#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iostream>
using namespace std;
int sum[100005];
int a[100005];
int q[100005];
double ans;
bool useless(int a,int b,int c)
{
	return (sum[c]-sum[b])*(b-a)<=(sum[b]-sum[a])*(c-b);
}
int main()
{
	int n,k;
    while(~scanf("%d%d",&n,&k)){
         for(int i=1;i<=n;i++){
         	scanf("%d",a+i);
         	sum[i]=sum[i-1]+a[i];
         }

         ans=0.0;
         int head=1;
         int tail=0;
         for(int i=k;i<=n;i++){
         while(head < tail && useless(q[tail-1],q[tail],i-k)) tail--;
         q[++tail]=i-k;
         while(head < tail && useless(q[head+1],q[head],i)) head++;
         ans = max(ans,(sum[i] - sum[ q[head] ]) * 1.0 / (i - q[head]));
         }
         printf("%.2f\n",ans);
    }
    return 0;
}
