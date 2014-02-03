#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX 123456789
struct node
{
    int x,y;
};
node vert[20001];
int res[20001];
int cmp(node a,node b)
{
    if(a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}
int find(int left,int right,int k)
{
    int mid;
    while(left < right)
    {
        mid=(left + right) >> 1;
        if(res[mid] >= k)
            left = mid+1;
        else 
            right=mid;
    }
    return left;
}
int work(int n)
{
    int i,pos,len=1;
    for(i=0;i<n;i++)
    {
        pos=find(0,len,vert[i].y);
        if(pos==len) 
            res[len++]=vert[i].y;
        else 
            res[pos]=vert[i].y;
    }
    return len;
}
int main()
{
    int i,m,n;
    scanf("%d",&n);
    while(n--)
    {
        memset(res,0,sizeof(res));
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d %d",&vert[i].x,&vert[i].y);
        sort(vert,vert+m,cmp);

        printf("%d\n",work(m));
    }
    return 0;
}