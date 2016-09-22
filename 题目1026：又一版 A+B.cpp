#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	int m;
	long long a,b;
	//对sum进行m进制转换
	long long sum=0;
	
	while(scanf("%d",&m)!=EOF)
	{
		scanf("%lld%lld",&a,&b);
		
		sum=a+b;
		int ans[50],size=0;
		//依次求的各个数位上的数字值
		do{
			ans[size++]=sum%m;
			sum/=m;

		}while(sum!=0);
		//输出,注意顺序为从高位到低位
		for(int i=size-1;i>=0;i--)
		{
			printf("%d",ans[i]);
		}

		printf("\n");
	}

}
