#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int l,n;
	int rec[610];
	
	
	//int all=0;
	int remain;
	//���������Ѿ���ʼ����λ�ú���Ҫ������
	while(scanf("%d%d",&l,&n)!=EOF)
	{
		int all=0;
		bool flag = false;  
		int sum=0;
		int count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&rec[i]);
			all+=rec[i];
		}
		sort(rec,rec+n,cmp);

		for(int i=0;i<n;i++)
		{
			sum+=rec[i];
			//remain=l-sum;
			//if(sum<=l)
			//{
			//	++count;
			//	//������������һ����Ĭ��һ���ܼ��ϣ�����
			//}else
			//{
			//	flag = false;
			//}
			count++;
			if(sum>=l)
			{
				flag = true;  
				break;
			}
		}
		if(flag==true)
		{			
			printf("%d\n",count);			
		}
		//Ϊʲôall�����ԣ�
		if(l>all && flag==false)
		{
			//printf("%d\n",count);
			//printf("%d  %d",all,sum);
			printf("impossible\n");
		}
		
	}
	return 0;
}
// 8 3
// 5 4 3