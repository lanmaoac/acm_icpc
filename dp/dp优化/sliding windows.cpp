#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#define eps 1e-6
#define INF 0x3fffffff
#define PI acos(-1.0)
#define ll __int64
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

#define Maxn 1100000
int sa[Maxn];
int q1[Maxn],q2[Maxn];
int ans1[Maxn],ans2[Maxn];

int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int n,k;

   while(scanf("%d%d",&n,&k)!=EOF)
   {
       for(int i=1;i<=n;i++)
            scanf("%d",&sa[i]);
       int h1=0,t1=-1;
       int h2=0,t2=-1,cnt=0;
       for(int i=1;i<=n;i++)
       {
            while(h1<=t1&&sa[i]<=sa[q1[t1]])
                t1--;
            while(h2<=t2&&sa[i]>=sa[q2[t2]])
                t2--;
            q2[++t2]=i;
            q1[++t1]=i;
            while(q1[h1]<i-k+1)
                h1++;
            while(q2[h2]<i-k+1)
                h2++;
            if(i>=k)
            {
                ans1[++cnt]=sa[q1[h1]];
                ans2[cnt]=sa[q2[h2]];
            }

       }
       printf("%d",ans1[1]);
       for(int i=2;i<=cnt;i++)
            printf(" %d",ans1[i]);
       printf("\n%d",ans2[1]);
       for(int i=2;i<=cnt;i++)
            printf(" %d",ans2[i]);
       putchar('\n');

   }
   return 0;
}