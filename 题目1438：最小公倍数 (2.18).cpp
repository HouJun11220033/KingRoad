#include<stdio.h>
using namespace std;
//最小公倍数：两个数的乘积除以两数的最大公约数
int gcd(int a,int b){
	if(b==0)
	{
		return a;
	}
	int temp;
	temp=b;
	b=(a%b);
	a=temp;
	gcd(a,b);
}
int main(){
	int n,m,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("%d\n",(n*m)/gcd(n,m));
	}
	return 0;
}