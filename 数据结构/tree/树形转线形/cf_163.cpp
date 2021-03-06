#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector<int>g[1000005];
int to[1000005][26],fail[1000005];
bool cont[1000005];
int que[1000005],k;
int w[1000005];
int col[1000005][2];
int dfn[1000005];
char str[1000005];
void add_trie(char a[],int s)
{
    int index,p=0;
    for(int i=0;a[i];i++)
    {
        index=a[i]-'a';
        if(to[p][index]==0)
            fail[k]=0,to[p][index]=k++;
        p=to[p][index];
    }
    w[s]=p;
}
void build_ac()
{
    int tail=0,front=0,p;
    for(int i=0;i<26;i++)
        if(to[0][i])
            fail[to[0][i]]=0,que[front++]=to[0][i];
    while(tail<front)
    {
        p=que[tail++];
        for(int i=0;i<26;i++)
            if(to[p][i])fail[to[p][i]]=to[fail[p]][i],que[front++]=to[p][i];
            else to[p][i]=to[fail[p]][i];
    }
    for(int i=1;i<k;i++)
        g[fail[i]].push_back(i);
}
void dfs(int s)
{
    col[s][0]=k;k++;//dfn[k++]=s;
    for(int i=0;i<g[s].size();i++)
        dfs(g[s][i]);
    col[s][1]=k;
}
int bit[1000005];
void updat(int x,int v)
{
    while(x<=k) bit[x]+=v,x+=x&-x;
}
int query(int x)
{
    int s=0;
    while(x) s+=bit[x],x-=x&-x;
    return s;
}
int sol(char a[])
{
    int p=0,ans=0;
    for(int i=0;a[i];i++)
        ans+=query(col[p=to[p][a[i]-'a']][0]);
    return ans;
}
int main()
{
    int n,q;
    scanf("%d%d",&q,&n);
    cont[0]=0;k=1;
    for(int i=0;i<n;i++)
        scanf("%s",str),add_trie(str,i);
    build_ac();k=1;dfs(0);
    for(int i=0;i<n;i++)
        cont[i]=1,updat(col[w[i]][0],1),updat(col[w[i]][1],-1);
    for(int i=0;i<q;i++)
    {
        scanf("%s",str);
        if(str[0]=='?')printf("%d\n",sol(str+1));
        else
        {
            sscanf(str+1,"%d",&n);
            int c=str[0]=='+';n--;
            if(c!=cont[n])
                cont[n]=c,c=c?1:-1,updat(col[w[n]][0],c),updat(col[w[n]][1],-c);
        }
    }
    return 0;
}