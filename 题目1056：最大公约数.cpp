#include<stdio.h>

int gcd(int a,int b){
	//ע����Ҫa����b��
	if(b==0)
	{
		return a;

	}else
	{
		//����,���Ϊ��b��a%b�����Լ��
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