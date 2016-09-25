#include<stdio.h>

int gcd(int a,int b){
	//注定是要a除以b的
	if(b==0)
	{
		return a;

	}else
	{
		//否则,则改为求b与a%b的最大公约数
		return gcd(b,a%b);
	}

}
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d\n",gcd(a,b));
		
	}
	return 0;
}