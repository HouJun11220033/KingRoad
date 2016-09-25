#include<stdio.h>
int gcd(int a,int b)
{
	return b!=0?gcd(b,a%b):a;
}
int main(){

	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		//最小公倍数为两数的乘积除以它们的最大公约数
		printf("%d\n",a*b/gcd(a,b));
	}

}