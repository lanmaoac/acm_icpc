#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
using namespace std;
struct node
{
  int speed;
  int pos;
}num[100010];
node b[100010];
int bis[1000100];
int n,cnt;
void init()
{
  cnt=0;
  memset(bis,0,sizeof(bis));
  memset(num,0,sizeof(num));
  memset(b,0,sizeof(b));
}
bool cmp(node a,node b)
{
  if(a.speed==b.speed)
    return a.pos>b.pos;
  else return a.speed>b.speed;
}
void add(int now,int a)
{
  while(now<1000100)
  {
   bis[now]+=a;
   now+=(-now)&now;
  }
}
long long int sum(int now)
{
  long long sum=0;
  while(now>0)
  {
  sum+=bis[now];
  now-=now&(-now);
  }
  return sum;
}
//本题要构造两个矩阵，其中一个为矩阵A，作为初始矩阵 
//f2  0   0 
//f1  0   0 
//1   0   0 
//另一个为矩阵B 
//b   a   c 
//1   0   0 
//0   0   1 
int main()
{
  while(scanf("%d",&n)!=EOF)
  {
    init();
    for(int i=0;i<n;i++)
     scanf("%d%d",&num[i].pos,&num[i].speed);
    sort(num,num+n,cmp);
    long long ans=0;
    node now=num[0];
    add(num[0].pos,1);
    int cao=0;
    for(int i=1;i<n;i++)
    {
      if(num[i].pos==now.pos&&num[i].speed==now.speed) cao++;
      else {now=num[i];cao=0;}
      ans+=sum(num[i].pos);
      add(num[i].pos,1);
      ans-=cao;
    }
    printf("%lld\n",ans);
  }
  return 0;
}
/*
#include<stdio.h>
#include<string.h>
#define mod 1000007
#define N 3
typedef long long LL;
struct Matrix
{
  LL mat[N][N];
};

Matrix unit_matrix =
{
  1, 0, 0,
  0, 1, 0,
  0, 0, 1
}; //单位矩阵

Matrix mul(Matrix a, Matrix b) //矩阵相乘
{
  Matrix res;
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
    {
      res.mat[i][j] = 0;
      for(int k = 0; k < N; k++)
      {
        res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        res.mat[i][j] %= mod;
      }
    }
  return res;
}

Matrix pow_matrix(Matrix a, LL n)  //矩阵快速幂
{
  Matrix res = unit_matrix;
  while(n != 0)
  {
    if(n & 1)
      res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}

int main()
{
  LL n, f1, f2, a, b, c, T;
  Matrix tmp, arr;
  scanf("%lld",&T);
  while(T--)
  {
    scanf("%lld%lld%lld%lld%lld%lld",&f1, &f2, &a, &b, &c, &n);
    if(n == 0)
      printf("%lld\n",(f2-f1*b-c + mod)%mod);
    if(n == 1)
      printf("%lld\n",(f1+mod)%mod);
    else if(n == 2)
      printf("%lld\n",(f2+mod)%mod);
    else
    {
      memset(arr.mat, 0, sizeof(arr.mat));
      arr.mat[0][0] = f2;  arr.mat[1][0] = f1;  arr.mat[2][0] = 1;
      tmp.mat[0][0] = b;   tmp.mat[0][1] = a;   tmp.mat[0][2] = c;
      tmp.mat[1][0] = tmp.mat[2][2] = 1;
      tmp.mat[1][1] = tmp.mat[1][2] = tmp.mat[2][0] = tmp.mat[2][1] = 0;
      Matrix p = pow_matrix(tmp, n-2);
      p = mul(p, arr);
      LL ans = (p.mat[0][0] + mod) % mod;
      printf("%lld\n",ans);
    }
  }
  return 0;
}
*/