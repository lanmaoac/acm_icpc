#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
//maxx[i][j]=max{maxx[i][k] operator(+,*) maxx[k+1][j} },表示i到j段的最大值是i到k段和k+1到j段构成的。
//所以三个for循环枚举区间长度，区间取点，以及分割点k的位置。
//因为区间长度由小到大，因为这样大区间都是由小区间组成的，
//这样保证求解大区间时，每个小区间的值已经求解出来了。
int dx[105][105]={0},dn[105][105]={0};  
char op[105]={0};  
int main()  
{  
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        memset(dn,-1,sizeof(dn));  
        memset(dx,0,sizeof(dx));  
        memset(op,0,sizeof(op));  
        int n=1,a=0;  
        while(scanf("%d%c",&a,&op[n]))  
        {  
            dx[n][n]=dn[n][n]=a;  
            if(op[n]=='\n') break;  
            n++;  
        }  
        for(int k=1;k<n;++k)  
         for(int i=1;i+k<=n;++i)  
          for(int j=i;j<i+k;++j)  
         {  
             int mx=0,mn=0;  
             if(op[j]=='+')  
             {  
                 mx=dx[i][j]+dx[j+1][i+k];  
                 mn=dn[i][j]+dn[j+1][i+k];  
             }  
             else  
             {  
                 mx=dx[i][j]*dx[j+1][i+k];  
                 mn=dn[i][j]*dn[j+1][i+k];  
             }  
             dx[i][i+k]=max(dx[i][i+k],mx);  
             if(dn[i][i+k]==-1) dn[i][i+k]=mn;  
             dn[i][i+k]=min(dn[i][i+k],mn);  
         }  
         printf("%d %d\n",dx[1][n],dn[1][n]);  
    }  
    return 0;  
}  