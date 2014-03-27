#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
//注意  数据的在相乘的时候有可能会超过 int类型，还有就是有时候题目要让某个条件满足不超过k个   可以用在这个数除以k
vector<pair<int,int> >edge;
vector<int>dis[1000005];
int main()
{
	long long int n,k;
	scanf("%I64d%I64d",&n,&k);
    for(int i=1;i<=n;i++){
    	int a;
    	scanf("%d",&a);
    	dis[a].push_back(i);
    }
    if(dis[0].size()!=1){
    	printf("-1");
        return  0;
    }
    for(int i=1;i<n;i++){
    	if(dis[i].size() > dis[i-1].size()*k){
    		printf("-1");
    		return 0;
    	}
    	for(int j=0;j<dis[i].size();j++){
    		edge.push_back(make_pair(dis[i][j],dis[i-1][j/k]));
    	}
    	if(i==1) --k;
    }
    printf("%d\n",edge.size());
    for(int i=0;i<edge.size();i++){
    	printf("%d %d\n",edge[i].first,edge[i].second);
    
    }
	return 0;
}
