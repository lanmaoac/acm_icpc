#include<cstdio>  
#include<cstring>  
#include<set>  
using namespace std;  
set<int> s;
//tongji sguzi chuxian de timu  yong set  
int num[100005];  
int main()  
{  
    int n,i,j,cur;  
    while(scanf("%d",&n)!=EOF)  
    {  
        s.clear();  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d",&num[i]);  
            s.insert(num[i]);  
            cur=num[i];  
            for(j=i-1;j>=1;j--)  
            {  
                cur|=num[j];  
                if(cur==num[j])  
                    break;  
                num[j]=cur;  
                s.insert(cur);  
            }  
        }  
        printf("%d\n",s.size());  
    }  
    return 0;  
}