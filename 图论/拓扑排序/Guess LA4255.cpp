#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <queue>  
#include <algorithm>  
#include <vector>  
#include <cstring>  
#include <stack>  
#include <cctype>  
#include <utility>     
#include <map>  
#include <string>    
#include <climits>   
#include <set>  
#include <string>      
#include <sstream>  
#include <utility>     
#include <ctime>  
  
using std::priority_queue;  
using std::vector;  
using std::swap;  
using std::stack;  
using std::sort;  
using std::max;  
using std::min;  
using std::pair;  
using std::map;  
using std::string;  
using std::cin;  
using std::cout;  
using std::set;  
using std::queue;  
using std::string;  
using std::istringstream;  
using std::make_pair;  
using std::greater;  
using std::endl;  
  
bool mp[15][15];  
char str[250];  
int indegree[15];  
int S[15];  
  
int main()  
{  
    int T;  
    scanf("%d", &T);  
    while(T--)  
    {  
        int n;  
        scanf("%d", &n);  
        scanf("%s", str);  
        int ind = 0;  
        memset(mp, 0, sizeof(mp));  
        memset(indegree, 0, sizeof(indegree));  
        for(int i = 1; i <= n; ++i)  
            for(int j = i; j <= n; ++j)  
            {  
                if(str[ind] == '-')  
                {  
                    mp[j][i-1] = true;  
                    ++indegree[i-1];  
                }  
                if(str[ind] == '+')  
                {  
                    mp[i-1][j] = true;  
                    ++indegree[j];  
                }  
                ++ind;  
            }  
        queue<int> que;  
        for(int i = 0; i <= n; ++i)  
            S[i] = -10;   
        for(int i = 0; i <= n; ++i)  
            if(indegree[i] == 0)  
            {  
                indegree[i] = -1;  
                que.push(i);  
            }  
        while(!que.empty())  
        {  
            int cur = que.front();  
            que.pop();  
            for(int i = 0; i <= n; ++i)  
                if(cur != i && mp[cur][i])  
                {  
                    --indegree[i];  
                    S[i] = max(S[i], S[cur]+1);  
                    if(indegree[i] == 0)  
                    {  
                        que.push(i);  
                        indegree[i] = -1;  
                    }  
                }  
        }  
        for(int i = 1; i <= n; ++i)  
        {  
            if(i != 1)  
                printf(" ");  
            printf("%d", S[i]-S[i-1]);  
        }  
        printf("\n");  
    }  
    return 0;  
}  