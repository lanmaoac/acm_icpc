#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
using namespace std;
class PairGameEasy
{
 public:
 	string able(int a, int b, int c, int d){
 		while(c>0 &&d>0)
 	       {
 	       	if(a==c&&d==b)
 	       		return  "Able to generate";
 	       	if(c>d) c-=d;
 	        else d-=c;
 	       }
        return  "Not able to generate";
 	}
};