//��ν�������ݣ����ǽ�b�����ö����Ʊ�ʾ����������λkλΪ1ʱ����Ҫ�۳�a��2^k�η�
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
				//ans������ɺ󣬶�����к���λ��������
				ans%=1000;
			}
			b/=2;
			a*=a;//��a������ƽ����һֱ���ڱ䣡����
			//a������ɺ󣬶�����к���λ��������
			a%=1000;

		}
		printf("%d\n",ans);

	}
	return 0;
	
}