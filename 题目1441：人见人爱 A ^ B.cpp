#include<stdio.h>
using namespace std;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF && a!=0 && b!=0)
	{
		int ans=1;

		while(b!=0)
		{
			//Ҳ����˵��Ӧ��������λΪ1
			if(b%2==1)
			{
				ans*=a;
				ans%=1000;	
			}
			a*=a;
			a%=1000;
			b/=2;
		}
		printf("%d\n",ans);
	}
	return 0;
}