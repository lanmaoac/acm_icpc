#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int base=500000;
bool flag[8],vis[25][25],mp[21][21][16384];
int n,m,l;
int xx[4]={-1,0,1,0};
int yy[4]={0,1,0,-1};
int front,rear;
struct Node
{
    int x,y;
    int step;
    int s[8];
    int p[8][2];
};
Node q[base];
int _pre(int sx,int sy,int _x,int _y)
{
     int x=_x-sx,y=_y-sy;
     if(x==-1) return 1;
     else if(x==1) return 3;
     else if(y==-1) return 2;
     return 0;
}
int adss(Node G)
{
        int va=G.s[0],vb=1,i;
    for(i=1;i<l-1;i++)
    {
        va=va*4+G.s[i];
    } 
 
    return va;
 
}
int itself(int x,int y,Node G)
{
    for(int i=0;i<l-1;i++)
    {
        if(x==G.p[i][0]&&y==G.p[i][1]) return 1;
    }
    return 0;
}
int bfs()
{
    while(front!=rear)
    {
        Node gg;
        front=(front+1)%base;
        gg=q[front];
        int vx=adss(q[front]);
        if(mp[gg.x][gg.y][vx])
            continue;
        mp[gg.x][gg.y][vx]=1;
      //  if(flag[v]) continue;
       // flag[v]=1;
        if(q[front].x==0&&q[front].y==0) return q[front].step;
        for(int i=0;i<4;i++)
        {
            int x,y;
            x=q[front].x+xx[i],y=q[front].y+yy[i];
            if(x<0 || y<0 || x>=n || y>=m || vis[x][y]) continue;
            if(itself(x,y,q[front])) continue;
            rear=(rear+1)%base;
            q[rear].x=x,q[rear].y=y,q[rear].step=q[front].step+1;
            for(int j=0;j<l-2;j++)
            {
                q[rear].s[j+1]= q[front].s[j];
                q[rear].p[j+1][0]=q[front].p[j][0];
                q[rear].p[j+1][1]=q[front].p[j][1];
            }
            q[rear].p[0][0]=q[front].x,q[rear].p[0][1]=q[front].y;
            q[rear].s[0]=_pre(x,y,q[front].x,q[front].y);
        }
    }
    return -1;
}
int main()
{
    int ci=1;
    while(scanf("%d%d%d",&n,&m,&l)==3&&n)
    {
        memset(vis,0,sizeof(vis));
        memset(flag,0,sizeof(flag));
        memset(mp,0,sizeof(mp));
        int x,y;scanf("%d%d",&x,&y);x--,y--;//头
        front=-1,rear=0;//队列头和尾
        q[0].x=x,q[0].y=y,q[0].step=0;
        int sx=x,sy=y;
        for(int i=0;i<l-1;i++)
        {
            scanf("%d%d",&x,&y);x--,y--;
            q[0].s[i]=_pre(sx,sy,x,y);
            q[0].p[i][0]=x,q[0].p[i][1]=y;//蛇身
            sx=x,sy=y;
        }
        int k;scanf("%d",&k);
        while(k--)
        {
            scanf("%d%d",&x,&y);x--,y--;
            vis[x][y]=1;
        }
        cout<<"Case "<<ci++<<": ";
        int cnt=bfs();
        printf("%d\n",cnt);
    }
    return 0;
}