#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

typedef long long LL;

int pos[1000000 + 5];

int main(){
	int x,y;
	scanf("%d %d",&x,&y);
	memset(pos,-1,sizeof(pos));
	x = x % y;
	int p = 0;
	while(1) {
		if(pos[x] != -1) {
			if(x != 0)
				printf("%d %d\n",pos[x],p - pos[x]);
			else printf("%d 0\n",pos[x]);
			return 0;
		}else{
			pos[x] = p;
			x = x * 10 % y;
		}
		p++;
	}
	return 0;
}