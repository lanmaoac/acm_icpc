#include <cstdio>  
#include <vector>  
#include <queue>  
#include <cstring>  
#define maxn 10010  
using namespace std;   
struct node  {  
    int v,dist;  
    node() {}  
    node(int _v, int _dist){  
        v = _v;  
        dist = _dist;  
    }  
} aux;  
bool visited[maxn];  
vector<int> L[maxn];    
node search(int v)  
{  
    node ans ;//= node(v,0);  
    queue<node> Q;  
    Q.push(node(v,0));  
    memset(visited,false,sizeof(visited));  
    visited[v] = true;  
    while(!Q.empty())  {  
        aux = Q.front();  
        Q.pop();  
        ans = aux;  
        for(int i = L[aux.v].size()-1; i >= 0; --i)  {  
            if(visited[L[aux.v][i]])  
                continue;  
            visited[L[aux.v][i]] = true;  
            Q.push(node(L[aux.v][i], aux.dist+1));  
        }  
    }  
    return ans;  
}   
int main()  
{  
    int N,u,v;  
    scanf("%d",&N);  
    for(int i = 1; i < N; ++i)  
    {  
        scanf("%d%d",&u,&v);  
        L[u].push_back(v), L[v].push_back(u);  
    }  
    printf("%d\n",search(search(1).v).dist);  
    return 0;  
} 