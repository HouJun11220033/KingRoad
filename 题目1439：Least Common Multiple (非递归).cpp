#include<stdio.h>
using namespace std;
int gcd(int a,int b)
{
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
	int n;
	int mul;
	int first;
	int count=0;
	int ans=0;
	int num=0;
	int a=1;
	while(scanf("%d",&n)!=EOF)
	{

		for(int i=0;i<n;i++)
		{
			int m;
			ans=0;
			count=0;
			mul=1;
			first=1;
			scanf("%d",&m);
			while(m--)
			{
				//求一堆数字的最小公倍数时候，不能只算第一个后面的所有数的成绩那不是LCM
				//俩俩求（前两个数的最后公倍数和后面那个数接着求最小公倍数）
				scanf("%d",&num);
				ans=(first/gcd(first,num))*num;
				first=ans;
			}

			printf("%d\n",ans);
		}
	}
}
