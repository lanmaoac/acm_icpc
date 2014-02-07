#include <stdio.h>  
#include <algorithm>  
#include <vector>  
#include <string.h>  
using namespace std;  
  
struct node  
{  
    int v;  
    int is, no;  
    vector<int> son;  
}a[6010];  
  
bool f[6010];  
  
void dp(int x)  
{  
    int t;  
    for (unsigned int i = 0; i < a[x].son.size(); i++)  
    {  
        t = a[x].son[i];  
        dp(t);  
        a[x].is += a[t].no;  
        a[x].no += max(a[t].no, a[t].is);  
    }  
}  
  
int main()  
{  
    int n;  
    while (scanf("%d", &n) != EOF)  
    {  
        for (int i = 1; i <= n; i++)  
        {  
            scanf("%d", &a[i].v);  
            a[i].son.clear();  
            a[i].is = a[i].v;  
            a[i].no = 0;  
        }  
        int son, fa;  
        memset(f, 0, sizeof(f));  
        while (scanf("%d %d",&son, &fa) && son+fa)  
        {  
            a[fa].son.push_back(son);  
            f[son] = 1;  
        }  
        for (int i = 1; i <= n; i++)  
        {  
            if (f[i] == false)  
            {  
                dp(i);  
                printf("%d\n",max(a[i].is, a[i].no));  
                break;  
            }  
        }  
    }  
    return 0;  
}  