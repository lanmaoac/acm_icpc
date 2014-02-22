#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <iostream>
using namespace std;
char s[1005];
struct node
{
	int num;
	int pos;
}a[1000000+10],q[1000000+10];
int main()
{ 
	int t;
	scanf("%d",&t);

    while(t--){
      while(1){
       int cnt=1;
	   int i=0;
	   int head=1;
	   int tail=0;
       scanf("%s",s);
       if(s[0]=='S') continue;
       if(s[0]=='E') break;
       if(s[0]=='Q'){
             if(head<=tail) printf("%d\n",q[head].num);
             else puts("-1");
       }
       else if(s[0]=='C'){
          i++;
          scanf("%s%d",s,&a[i].v);
          a[i].pos=i;
          while(head<=tail && q[tail].num<a[i].num ) tail--;
          q[++tail]=a[i];
      }
      else {
      	j++;
      	if(q[head].pos<j) head++;
      }
   }
 }    
 return 0;
}