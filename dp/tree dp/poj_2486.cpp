#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> g[1010];
int dp[2][1010][210];
int n,V,val[1010];
bool used[1010];
void Max(int &a,int b){
    if(a<b) a=b; 
}
void dfs(int s){
    int i;
    used[s]=true;
    for(i=0;i<=V;i++){
         dp[0][s][i]=dp[1][s][i]=val[s];//强制加入
    }
    for(i=0;i<g[s].size();i++){
        int t=g[s][i];
        if(used[t]) continue;
        dfs(t);
        for(int j=V;j>=0;j--){
            for(int k=0;k<=j;k++){//中间的桥梁一定要走，所以把状态依次转变过来
                Max(dp[0][s][j+2],dp[0][t][k]+dp[0][s][j-k]);
                Max(dp[1][s][j+2],dp[0][t][k]+dp[1][s][j-k]);
                Max(dp[1][s][j+1],dp[1][t][k]+dp[0][s][j-k]);
            }
        }
    }
}
int main(){
    int i,a,b;
    while(scanf("%d%d",&n,&V)!=EOF){
        for(i=0;i<=1000;i++)
            g[i].clear();
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        for(i=0;i<n-1;i++){
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(dp,0,sizeof(dp));
        memset(used,false,sizeof(used));
        dfs(1);
        printf("%d\n",dp[1][1][V]);
    }
    return 0;
}