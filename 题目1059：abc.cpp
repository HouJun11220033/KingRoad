#include<stdio.h>
using namespace std;
int main(){
	int a,b,c;
	int sum=0;
	int num1,num2;
	for(int i=0;i<=9;i++)
	{
		a=i;
		for(int j=0;j<=9;j++)
		{
			b=j;
			for(int k=0;k<=9;k++)
			{
				c=k;
				num1=a*100+b*10+c;
				num2=b*100+c*10+c;
				if(num1+num2==532)
				{
					printf("%d %d %d\n",a,b,c);
				}

			}
		}
	}

	return 0;
}