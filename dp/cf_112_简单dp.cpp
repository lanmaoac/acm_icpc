#include <cstdio>
using namespace std;

char s[1000005];
int dp[1000005]={1},c,m;
long long ans;

int main(){
    scanf("%d%s",&m,s);
    for(int i=0;s[i];i++){
        if(s[i]=='1') c++;
        if(c>=m) ans+=dp[c-m];
        dp[c]++;
    }
    printf("%I64d\n",ans);
}