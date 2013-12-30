#include <cstdio>  
#include <iostream>  
#include <cstring>  
#include <map>  
#include <iostream>  
#include <vector>  
#include <algorithm>  
#define maxn 100010  
using namespace std;  
int n,k,t,a[maxn],Q,head[maxn],esub,linr[maxn],L[maxn],R[maxn],li,ans[maxn];  
int c[maxn];  
vector < int > pl[maxn];//用来记录值出现的位置  
bool cmpx(int x, int y){  
    return a[x] < a[y];  
}  
void dis(){  
    int tmp = -1,r[maxn];  
    for(int i = 1; i <= n; i ++)  
        r[i] = i;  
    sort(r + 1, r + 1 + n, cmpx);  
    int prev = a[r[1]] - 1;//必须要有一个prev将原来的值记录下来，不然原来的值就保存不下来了  
    for(int i = 1; i <= n; i ++)  
        if(prev != a[r[i]]) prev = a[r[i]],a[r[i]] = ++ tmp;  
        else { a[r[i]] = tmp;}  
  
    for(int i = 0; i <= tmp; i ++){  
        pl[i].clear();//初始化很重要  
        pl[i].push_back(0); //假设每个值都在第0个位置出现  
    }  
}  
struct query{  
    int L,R,id;  
    bool operator < (const query& cmp) const{  
        return R < cmp.R;  
    }  
}q[maxn];  
struct Edge{  
    int v,nxt;  
}edge[maxn << 1 ];//  
void init(){  
    esub = 0;   li = 0;  
    memset(head,-1,sizeof(head));  
    memset(c,0,sizeof(c));  
    memset(L,0,sizeof(L));  
}  
void add(int u, int v){  
    edge[esub].v = v;  
    edge[esub].nxt = head[u];  
    head[u] = esub ++;  
}  
void dfs(int rt){  
    L[rt] = ++li;   linr[li] = a[rt];  
    for(int j = head[rt]; j != -1; j = edge[j].nxt){  
        if(!L[edge[j].v])   dfs(edge[j].v);  
    }  
    R[rt] = li;  
}  
void modify(int pos, int val){  
    while(pos <= n){  
        c[pos] += val;  
        pos += (pos & (-pos) );  
    }  
}  
int getsum(int pos){  
    int sum = 0;  
    while(pos){  
        sum += c[pos];  
        pos -= (pos & (-pos) );  
    }return sum;  
}  
int main(){  
    scanf("%d",&t);  
    for(int ca = 1; ca <= t; ca ++){  
        printf("Case #%d:\n",ca);  
        scanf("%d%d",&n,&k);  
        init();//  
        for(int i = 1; i <= n; i ++){  
            scanf("%d",&a[i]);  
        }  
        dis();//从小到大离散化，可以不用从小到大，只要相同的依旧相同，不同的依旧不同就行  
  
        for(int i = 1; i < n; i ++){  
            int a,b;  
            scanf("%d%d",&a,&b);  
            add(a,b);  
            add(b,a);  
        }  
        dfs(1); //产生一个线性序列  
        scanf("%d",&Q);  
        for(int i = 1; i <= Q; i ++){  
            int x;  
            scanf("%d",&x);  
            q[i].L = L[x];  
            q[i].R = R[x];  
            q[i].id = i;  
        }  
        sort(q + 1, q + 1 + n);  
        int qsub = 1;  
        for(int i = 1; i <= n; i ++){  
            int v = linr[i];  pl[v].push_back(i);//记录linr[i]出现的位置  
            int g = pl[v].size() - 1;  
            if(g >= k){  
                if(g > k){  
                    modify(pl[v][g - k - 1] + 1, -1);  
                    modify(pl[v][g - k] + 1, 1);  
                }  
                modify(pl[v][g - k] + 1, 1);  
                modify(pl[v][g - k + 1] + 1, -1);  
            }  
            while( q[qsub].R == i){  
                ans[q[qsub].id] = getsum(q[qsub].L);  
                qsub ++;  
            }  
        }  
        for(int i = 1; i <= Q; i ++)  
            printf("%d\n",ans[i]);  
  
        if(ca < t) puts("");  
    }  
    return 0;  
}  
