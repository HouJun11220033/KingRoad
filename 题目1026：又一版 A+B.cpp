#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	int m;
	long long a,b;
	//��sum����m����ת��
	long long sum=0;
	
	while(scanf("%d",&m)!=EOF)
	{
		scanf("%lld%lld",&a,&b);
		
		sum=a+b;
		int ans[50],size=0;
		//������ĸ�����λ�ϵ�����ֵ
		do{
			ans[size++]=sum%m;
			sum/=m;

		}while(sum!=0);
		//���,ע��˳��Ϊ�Ӹ�λ����λ
		for(int i=size-1;i>=0;i--)
		{
			printf("%d",ans[i]);
		}

		printf("\n");
	}

}
