#include<stdio.h>
using namespace std;
int main(){
	int n,x,y,z;
	while(scanf("%d",&n)!=EOF)
	{
		int sum=0;
		int max=0;
		int price;
		int i_ans=0;
		int j_ans=0;
		int cnt=0;
		scanf("%d%d%d",&x,&y,&z);
		sum=x*1000+y*100+z*10;
		for(int i=1;i<=9;i++)
		{
			int new_i_sum;
			new_i_sum=i*10000+sum;
			for(int j=0;j<=9;j++)
			{
				int new_j_sum;
				new_j_sum=(new_i_sum+j);
				if(new_j_sum%n==0)
				{
					cnt++;
					price=new_j_sum/n;
					if(price>max)
					{
						max=price;
						i_ans=i;
						j_ans=j;
					}					
				}				
			}
		}
		if(cnt==0)
		{
			printf("0\n");
			//return 0;
		}else//不要用直接用return，用else巧妙回避
		{
			printf("%d %d %d\n",i_ans,j_ans,max);
		}
	}

	return 0;
}
