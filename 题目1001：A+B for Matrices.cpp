#include<stdio.h>
int main(){
	int a[300][300];
	int b[300][300];
	int m,n;
	int count1=0;
	int count2=0;
	bool flag1=true;
	bool flag2=true;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0)
		{
			return 0;
		}
		for(int i=0;i<m*2;i++)
		{
			
			for(int j=0;j<n;j++)
			{
				//a[i][j]=scanf("%d",&value);
				scanf("%d",&a[i][j]);
			}
			
		}
		for(int i=0;i<m;i++)
		{
			
			for(int j=0;j<n;j++)
			{
				b[i][j]=a[i+m][j]+a[i][j];
			}
			
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				//i不动，j动
				if(b[i][j]!=0)
				{
					flag1=false;
					
				}
				/*if(b[i][j]==0 && i>=1 && b[i-1][j]!=0)
				{
					flag2=false;
				}*/
			}
			//一行遍历完如果都是0
			if(flag1)
			{
				count1++;
			}
			/*if(flag2)
			{
				count++;
			}*/
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(b[j][i]!=0)
				{
					flag2=false;
				}
			}

		
			if(flag2)
			{
				count2++;
			}
		}
		printf("%d\n",count1+count2);

	}


	return 0;
}