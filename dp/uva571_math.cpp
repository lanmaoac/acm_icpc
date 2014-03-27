#include <cstdio>
#include <cstring>
int ca,cb,n,a,b;


int main()
{
    while(scanf("%d%d%d",&ca,&cb,&n)!=EOF)
    {
        if(cb==n)
        {
            printf("fill B\n");
            printf("success\n");
            continue;
        }
        a=b=0;
        while(b!=n)
        {
            if(a==0)  //A瓶为空，加满
            {
                printf("fill A\n");
                a=ca;
            }
            if(b<cb)  //b瓶没没有满
            {
                printf("pour A B\n");
                if(b+ca>cb)  //B先满，A不为空
                {
                    a=ca-(cb-b);
                    b=cb;
                }
                else      //A为空，B未满或者满都有可能
                {
                    b=b+a;
                    a=0;
                }
            }
            if(b==cb)
            {
                printf("empty B\n");
                b=0;
                printf("pour A B\n");
                b=a;
                a=0;
            }
        }
        printf("success\n");
    }
    return 0;
}