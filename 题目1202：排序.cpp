#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int a[200];

	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);

		}
		
		//冒泡排序
		//循环一次排好1个值
		//这样一趟过去后,最大或最小的数字被交换到了 “最后一位”
		//for(int i=0;i<n;i++)
		//{
		//	//j的终止位置一直向左移
		//	for(int j=0;j<n-1-i;j++)
		//	{
		//		if(a[j]>a[j+1])
		//		{
		//			int temp=a[j];
		//			a[j]=a[j+1];
		//			a[j+1]=temp;
		//		}
		//	}
		//}
		//for(int i=0;i<n;i++)
		//{
		//	for(int j=i+1;j<n;j++)
		//	{
		//		if(a[i]>a[j])
		//		{
		//			int temp=a[i];
		//			a[i]=a[j];
		//			a[j]=temp;
		//		}
		//		
		//	}
		//}
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	
}