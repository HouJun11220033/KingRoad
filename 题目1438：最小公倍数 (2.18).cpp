#include<stdio.h>
using namespace std;
//��С���������������ĳ˻��������������Լ��
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