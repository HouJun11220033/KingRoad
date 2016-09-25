#include<stdio.h>

int gcd(int a,int b)
{
	if(b==0)
	{
		return a;
	}else
	{
		//直到除数等于0
		gcd(b,a%b);
	}
}

int LCM(int a,int b)
{
	//注意这里不能用a*b/gcd(a,b)，数据会溢出!!!

	//return a*b/gcd(a,b);
	return a / gcd(a, b) * b;

}

int inPut[1100][1100];
int count[1100];
int result[1100];
int main(){
	 int n;
	 int m;
	 int ee=0;
	 while(scanf("%d",&n)!=EOF)
	 {
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			count[i]=m;
			for(int j=0;j<m;j++)
			{
				scanf("%d",&inPut[i][j]);
			}
		}
		for(int i=0;i<n;i++)
		{

			ee=LCM(inPut[i][0],inPut[i][1]);
			for(int j=2;j<count[i];j++)
			{
				/*for(int k=j;k<count[i];k++)
				{

				}*/
				//if(j<count[i])
				//{
				
					ee=LCM(ee,inPut[i][j]);

				//前三个数的LCM
					/*ee=LCM(ee,inPut[i][j+2]);
					j=2;*/
				
			//	}else
			//	{
			//		break;
			//	}
			}
			result[i]=ee;
		}
		for(int i=0;i<n-1;i++)
		{
			printf("%d\n",result[i]);
		}
		printf("%d",result[n-1]);
	 }
	 return 0;
}