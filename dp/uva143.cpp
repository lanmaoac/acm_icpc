#include <cstdio>
 2 #include <cmath>
 3 #include <algorithm>
 4 using namespace std;
 5 #define EPS 1e-9
 6 
 7 double area2(double x0, double y0, double x1, double y1, double x2, double y2)
 8 {
 9     return fabs(x0*y1 + x2*y0 + x1*y2 - x2*y1 - x0*y2 - x1*y0);
10 }
11 
12 int main()
13 {
14 #ifdef LOCAL
15     freopen("in", "r", stdin);
16 #endif
17     double x1, x2, x3, y1, y2, y3;
18     while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
19     {
20         if ((x1 || x2 || x3 || y1 || y2 || y3) == 0)  break;
21         int x_min = ceil(min(x1, min(x2, x3)));
22         x_min = max(1, x_min);
23         int x_max = max(x1, max(x2, x3));
24         x_max = min(99, x_max);
25         int y_min = ceil(min(y1, min(y2, y3)));
26         y_min = max(1, y_min);
27         int y_max = max(y1, max(y2, y3));
28         y_max = min(99, y_max);
29         double S = area2(x1, y1, x2, y2, x3, y3);
30         int ans = 0;
31         for (int x = x_min; x <= x_max; x++)
32             for (int y = y_min; y <= y_max; y++)
33             {
34                 double S1 = area2(x1, y1, x2, y2, x, y);
35                 double S2 = area2(x2, y2, x3, y3, x, y);
36                 double S3 = area2(x3, y3, x1, y1, x, y);
37                 if (fabs(S-S1-S2-S3) < EPS)  ans++;
38             }
39         printf("%4d\n", ans);
40     }
41     return 0;
42 }