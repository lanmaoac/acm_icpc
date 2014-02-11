#include <cstdio>  
#include <cmath>  
#include <iostream>  
#include <cstring>  
# define MAX 222  
# define INF 0x7FFFFFFF  
using namespace std;  
  
struct node {  
    int s,e,v,next;  
} ed[MAX];  
int head[MAX],num = 0,n,m,tim,flag,timee;  
int dp[MAX][5555],va[MAX]; // dp[i][j] 表示回到i点时使用了j的时间能获得的最多的权值  
  
void add(int s,int e,int v) {  
    ed[num].s = s;  
    ed[num].e = e;  
    ed[num].v = v;  
    ed[num].next = head[s];  
    head[s] = num++;  
}  
  
void init() {  
    memset(head,-1,sizeof(head));  
    num = 0;  
    flag = 0;  
    timee = 0;  
}  
  
int dfstime(int v0,int pre) {  
    if(v0 == n) return 1;  
    for(int i=head[v0];i != -1; i =ed[i].next) {  
        int e = ed[i].e ;  
        if(e != pre) {  
            if(dfstime(e,v0)) {  
                timee += ed[i].v;  
                ed[i].v = 0;  
                return 1;  
            }  
        }  
    }  
    return 0;  
}  
  
void dfs(int v0,int pre) {  
    for(int i=0; i<=tim; i++) dp[v0][i] = va[v0];  
    for(int i=head[v0];i != -1; i = ed[i].next) {  
        int e = ed[i].e ;  
        if(e != pre) {  
            dfs(e,v0);  
            int cost = ed[i].v * 2;  
            for(int j=tim; j>=cost; j--) {  
                for(int k=0; k<=j -cost; k++) {  
                    dp[v0][j] = max(dp[v0][j],dp[e][k] + dp[v0][j-k-cost]);  
                }  
            }  
        }  
    }  
}  
  
int main() {  
    int i,a,b,c;  
    while(cin >> n >> tim) {  
        init();  
        for(i=0; i<n-1; i++) {  
            scanf("%d%d%d",&a,&b,&c);  
            add(a,b,c);  
            add(b,a,c);  
        }  
        for(i=1; i<=n; i++) {  
            scanf("%d",&va[i]);  
        }  
        dfstime(1,-1);  
        if(tim < timee) {  
            printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");  
            continue;  
        }  
        tim -= timee ;//最短路上的花费已经为0  
        dfs(1,-1);  
        printf("%d\n",dp[1][tim]);  
    }  
    return 0;  
}  