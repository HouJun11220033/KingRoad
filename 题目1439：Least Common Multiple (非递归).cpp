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
				//��һ�����ֵ���С������ʱ�򣬲���ֻ���һ��������������ĳɼ��ǲ���LCM
				//������ǰ����������󹫱����ͺ����Ǹ�����������С��������
				scanf("%d",&num);
				ans=(first/gcd(first,num))*num;
				first=ans;
			}

			printf("%d\n",ans);
		}
	}
}
