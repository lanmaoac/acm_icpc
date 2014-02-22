#include <cstdio>  
#include <iostream>  
using namespace std;  
const int mm=111111;  
int a[mm],qa[mm],qb[mm];  
int main()  
{  
    int i,n,m,k,ans,l,la,ra,lb,rb;  
    while(~scanf("%d%d%d",&n,&m,&k))  
    {  
        ans=l=la=lb=0,ra=rb=-1;  
        for(i=1;i<=n;++i)  
        {  
            scanf("%d",&a[i]);  
            while(la<=ra&&a[qa[ra]]>a[i])--ra;  
            while(lb<=rb&&a[qb[rb]]<a[i])--rb;  
            qa[++ra]=i;  
            qb[++rb]=i;  
            while(a[qb[lb]]-a[qa[la]]>k)  
                l=(qa[la]<qb[lb])?qa[la++]:qb[lb++];  
            if(a[qb[lb]]-a[qa[la]]>=m&&a[qb[lb]]-a[qa[la]]<=k)ans=max(ans,i-l);  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}