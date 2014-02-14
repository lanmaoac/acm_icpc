#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int f[20];
long long work(long long x){
    long long ret=0, u=x;
    int t=0, s=0;
    while(u) f[++t]=u%10, u/=10;
    for(int i=t; i>=1; --i){
        if(i==1){
            for(int j=0; j<f[i]; ++j)
                if((s+j)%10==0) ret++;
            break;
        }
        for(int j=0; j<f[i]; ++j)
            ret+=(long long) pow(10.0, i-2);
        s=(s+f[i])%10;
    }
    return ret;
}
int main(){
    int T, cas=1; scanf("%d",&T);
    while(T--){
        long long a, b;
        scanf("%I64d%I64d", &a, &b);
        printf("Case #%d: %I64d\n", cas++, work(b+1)-work(a));
    }
    return 0;
}