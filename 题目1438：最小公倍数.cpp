#include<stdio.h>
int gcd(int a,int b)
{
	return b!=0?gcd(b,a%b):a;
}
int main(){

	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		//��С������Ϊ�����ĳ˻��������ǵ����Լ��
		printf("%d\n",a*b/gcd(a,b));
	}

}