#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
const int N = 100005;
LL dp[N];
LL M,def[N*2],a[N];
LL n,m;
int main()
{
    while(scanf("%lld %lld",&n,&m)!=EOF){
    	LL sum=0;
    	LL head=0;
    	LL tail=0;
    	for(LL i=1;i<=n;i++){
    		scanf("%lld",a+i);
    		if(a[i]>m)
    			sum=-1;
    	}
    	if(sum==-1) {printf("-1\n");continue;}
    	sum=a[1];
    	dp[1]=a[1];
    	LL p=1;
    	head=1;
    	for(LL i=2;i<=n;i++){
    		sum+=a[i];
    		while(sum > m && p<i){
                sum-=a[p];
                p++;
            }
            while(head<=tail && a[def[tail]]<=a[i]) tail--;
            def[++tail]=i;
            while(def[head]<p && head<tail) head++;
            if(p==1) dp[i]=a[def[head]];
            else  dp[i]=dp[p-1]+a[def[head]];
            for(LL j=head;j<tail;j++)
            	dp[i]=min(dp[i],dp[def[j]]+a[def[j+1]]);
        }
        printf("%lld\n",dp[n]);
    }
	return 0;
}
