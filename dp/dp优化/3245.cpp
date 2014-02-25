#include<cstdio>  
#include<cstring>  
#include<set>  
#include<algorithm>  
using namespace std;  
  
const int maxn = 50000+100;  
  
int a[maxn],b[maxn],q[maxn],f[maxn],p[maxn];  
int n,limit,sum,tmp;  
multiset<int> bst;  
  
bool cmp(int v,int u)  
{  
    return b[v]<b[u];  
}  
  
bool check(int m)  
{  
    int l,r;  
    l=f[0]=0;  
    f[n]=r=-1;  
    int pos=1;  
    sum=0;  
    bst.clear();  
  
    for(int i=1;i<=n;i++)  
    {  
        sum+=b[i];  
        while(sum>m)  
            sum-=b[pos++];  
        if(pos>i)  
            return false;  
        while(l<=r && a[i]>=a[q[r]])  
        {  
            if(l<r)  
                bst.erase(f[q[r-1]]+a[q[r]]);  
            r--;  
        }  
  
        q[++r] = i;  
        if(l<r) bst.insert(f[q[r-1]]+a[q[r]]);  
  
        while(q[l]<pos)  
        {  
            if(l<r)  
                bst.erase(f[q[l]]+a[q[l+1]]);  
            l++;  
        }  
  
        f[i] = f[pos-1]+a[q[l]];  
  
        tmp = *bst.begin();  
  
        if(l<r && f[i]>tmp)  
            f[i]=tmp;  
    }  
  
    return f[n]<=limit;  
}  
  
  
  
int main()  
{  
    scanf("%d%d",&n,&limit);  
  
    int i,j;  
  
    for(i=1;i<=n;i++)  
    {  
        scanf("%d%d",&a[i],&b[i]);  
        q[i]=p[i]=i;  
    }  
  
    sort(p+1,p+1+n,cmp);  
  
    for(j=1,i=n;i>0;i--)  
    {  
        while(j<=n && b[p[j]]<=a[i])  
            q[p[j++]]=i;  
    }  
  
    int l,r;  
  
    for(i=1,j=1;i<=n;i=l,j++)  
    {  
        a[j]=a[i],b[j]=b[i];  
        for(l=i+1,r=max(q[i],i);l<=r;l++)  
        {  
            a[j] = max(a[j],a[l]);  
            b[j] +=b[l];  
            r=max(r,q[l]);  
        }  
    }  
  
    l=0,r=0x3f3f3f3f;  
    int ans;  
    n=j-1;  
  
    while(l<=r)  
    {  
        int mid = (l+r)>>1;  
        if(check(mid))  
            ans=mid,r=mid-1;  
        else  
            l=mid+1;  
    }  
  
    printf("%d\n",ans);  
  
    return 0;  
}  