#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
		double a,b,c;
		scanf("%lf%lf%lf",&a,&b,&c);
		double alpha = acos((c*c + b*b - a*a)/(2*c*b));
		printf("%.2lf\n",b*c*0.5*sin(alpha));
}
