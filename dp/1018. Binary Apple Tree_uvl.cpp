#include <cstdio> 
#include <vector> 
#include <string.h> 
using namespace std; 
const int M1 = 111; 
const int INF = 111111111; 
int N,Q; 
int total; 
int an[M1]; 
int sn[M1]; 
int pa[M1]; 
int edge[M1][M1]; 
bool mark[M1]; 
bool root; 
vector<int> tree[M1]; 
int f[M1][M1]; 
    
void dfs(int n,int p); 
int dp(int r,int n); 
int main() 
{ 
    scanf("%d%d",&N,&Q); 
    for(int i=1;i!=N;++i) 
    {   int f,t,w; 
        scanf("%d%d%d",&f,&t,&w); 
        edge[f][t] = edge[t][f] = w; 
        total += w; 
        tree[f].push_back(t); 
        tree[t].push_back(f); 
    } 
    pa[1]=0; tree[1].push_back(0); 
    dfs(1,0); 
    memset(f,-1,sizeof(f)); 
    for(int i=0;i<=N;++i) 
    {   f[i][0] = 0; 
        f[i][1] = an[i]; 
    } 
    int ans = dp(1,Q+1); 
    printf("%d\n",ans); 
    return 0; 
} 
void dfs(int n,int p) 
{ 
    pa[n] = p; 
    sn[n] = 1; 
    an[n] = edge[p][n]; 
    for(int i=0;i!=tree[n].size();++i) 
        if(tree[n].at(i)!=p) 
        {   dfs(tree[n].at(i),n); 
            sn[n] += sn[tree[n][i]]; 
        } 
} 
int dp(int r,int n) 
{ 
    if(f[r][n]!=-1) return f[r][n]; 
    if(n>sn[r]) 
    {   f[r][n] = 0; 
        return 0; 
    } 
    int res = an[r]; 
    int s[2],c=0; 
    for(int i=0;i!=3;++i) 
        if(tree[r][i]!=pa[r]) 
            s[c++] = tree[r][i]; 
    for(int i=0;i<n;++i) 
    {   int n1 = dp(s[0],i); 
        int n2 = dp(s[1],n-1-i); 
        if(res<n1+n2+an[r]) 
            res = n1+n2+an[r]; 
    } 
    f[r][n] = res; 
    return res; 
}