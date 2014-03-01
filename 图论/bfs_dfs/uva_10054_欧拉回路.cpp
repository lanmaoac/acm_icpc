#include<cstring>  
#include<iostream>  
#include<cstdio>  
#include<cmath>  
#include<stack>  
#define MAXN 60  
using namespace std;  
int vis[MAXN],cnt[MAXN],G[MAXN][MAXN],T, vis2[MAXN][MAXN], N, a, b;  
struct Node {int u,v; };  
stack<Node>st;  
  
void dfs(int u){  
    vis[u] = true;  
    for(int i=0; i<MAXN; ++i){  
        if(G[u][i] && !vis[i])  
            dfs(i);  
    }  
}  
  
void euler(int u){  
    for(int v=0; v<MAXN; ++v) if(G[u][v]){  
        --G[u][v]; --G[v][u];  
        euler(v);  
        Node t;  
        t.u = u, t.v = v;  
     // st.push(t);  
        printf("%d %d\n", u,v);  
    }  
}  
  
int main(){  
#ifdef LOCAL  
   freopen("input.txt","r",stdin);  
#endif   
    int cas=1;  
    scanf("%d",&T);  
    while(T--){  
        memset(G, 0, sizeof(G));  
        memset(cnt, 0, sizeof(cnt));  
  
        scanf("%d",&N);  
        for(int i=0; i<N; ++i){  
            scanf("%d %d",&a,&b);   
            ++G[a][b];  
            ++G[b][a];  
            ++cnt[a];  
            ++cnt[b];  
        }  
  
        bool flag=true;  
        for(int i=0; i<MAXN; ++i){  
            if(cnt[i] & 1){ flag=false; break;}  
        }  
      
        printf("Case #%d\n",cas++);  
  
        if(flag){  
            memset(vis, 0, sizeof(vis));  
            memset(vis2, 0, sizeof(vis2));  
  
            int flag2=true;  
  
            for(int i=0; i<MAXN; ++i)   
                if(cnt[i]) { dfs(i); break; }  
            for(int i=0; i<MAXN; ++i){  
                if(cnt[i] && !vis[i]) {flag2=false; break;}  
            }  
            if(flag2){  
                for(int i=0; i<MAXN; ++i) if(cnt[i]){  
                    euler(i);  
                    break;  
                }  
                // 这里可以递归时直接逆向打印，也可存到栈里在打印出来  
     //          while(!st.empty()){  
    //                printf("%d %d\n", st.top().u, st.top().v);  
      //              st.pop();  
          //     }  
            }  
            else printf("some beads may be lost\n");  
        }  
        else{<span style="color:#000099;">  
            printf("some beads may be lost\n");</span>  
        }  
        if(T) printf("\n");  
    }  
    return 0;  
} 