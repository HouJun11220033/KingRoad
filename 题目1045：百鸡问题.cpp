#include<stdio.h>
#include<algorithm>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//��ö��x,y,z�ĸ���ȫ��������Ҳ���Ƿŵ��������棬����жϳ��Լ۸���Ƿ����100
		//ö��x��ֵ

		for(int x=0;x<=100;x++)
		{
			for(int y=0;y<100-x;y++)
			{
				//����������ȱ�֤��x+y+z��ֵ����100
				int z=100-x-y;
				//����ʽ����ͬʱ����һ����,���⾫����ʧ
				if(x*5*3+y*3*3+z<=n*3)
				{
					printf("x=%d,y=%d,z=%d\n",x,y,z);
				}
				
			}
			
		}
	}


	return 0;
}