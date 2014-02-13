#include<iostream> 
#include<cstdio>
 #include<cstdlib>
  #include<algorithm> 
  #include<cmath> 
  #include<queue> 
  #include<set> 
  #include<map> 
  #include<cstring>
   #include<vector>
    #include<string>
     #define LL long long using namespace std; 
LL num[12]={1LL,10LL,100LL,1000LL,10000LL,100000LL,1000000LL,10000000LL,100000000LL,1000000000LL,
    10000000000LL,100000000000LL};
     LL Solve( LL n , int d ) 
     { LL sum = 0,left,a; for( int i = 1 ; i < 12 ; i ++ )
      { left = n / num[i] - ( d == 0 ); 
        sum += left*num[i-1]; 
        a = ( n % num[i] - n%num[i-1] )/num[i-1]; 
        if( a > d ) sum += num[i-1]; else if( a == d ) sum += n%num[i-1] +1;
         if( n < num[i] ) break; } return sum; 
     } 
 int main( ) 
 { LL n,m; 
    while( scanf( "%I64d %I64d",&n,&m ),n||m )
     { if( m > n ) swap( n ,m ); for( int i = 0; i <= 9 ; i ++ )
 printf( "%I64d ",Solve( n , i ) - Solve( m - 1 ,i ) ); puts( "" ); 
 } //system( "pause" ); return 0; }