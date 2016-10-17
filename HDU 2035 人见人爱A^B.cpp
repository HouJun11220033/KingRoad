//所谓二分求幂，即是将b次幂用二进制表示，当二进制位k位为1时，需要累乘a的2^k次方
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==0 && b==0)
		{
			break;
		}
		int ans=1;
		while(b!=0)
		{
			if(b%2==1)
			{
				
				ans*=a;
				//ans计算完成后，对其进行后三位保留处理
				ans%=1000;
			}
			b/=2;
			a*=a;//对a累求其平方！一直都在变！！！
			//a计算完成后，对其进行后三位保留处理
			a%=1000;

		}
		printf("%d\n",ans);

	}
	return 0;
	
}