#include<stdio.h>
#include<algorithm>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//先枚举x,y,z的各自全部数量，也就是放到数组里面，最后判断乘以价格后是否等于100
		//枚举x的值

		for(int x=0;x<=100;x++)
		{
			for(int y=0;y<100-x;y++)
			{
				//到这里，必须先保证，x+y+z的值等于100
				int z=100-x-y;
				//不等式两边同时乘以一个数,避免精度损失
				if(x*5*3+y*3*3+z<=n*3)
				{
					printf("x=%d,y=%d,z=%d\n",x,y,z);
				}
				
			}
			
		}
	}


	return 0;
}