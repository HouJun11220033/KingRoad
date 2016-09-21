#include<stdio.h>
#include<string.h>
int dp[101][101];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	char s1[101],s2[101];
	while(scanf("%s%s",s1,s2)!=EOF)
	{
		int L1=strlen(s1);
		int L2=strlen(s2);
		//竖着
		for(int i=0;i<=L1;i++)
		{
			dp[i][0]=0;
		}
		//横着
		for(int j=0;j<=L2;j++)
		{
			dp[0][j]=0;
		}
		//二维数组从上到下(横着的一行一行给竖着的比)
		//这里的比较是两个字符串，不是全局数组
		for(int i=1;i<=L1;i++)
		{
			for(int j=1;j<=L2;j++)
			{
				if(s1[i-1]!=s2[j-1])
				{
					dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
				}
				else{
					dp[i][j]=dp[i-1][j-1]+1;
				}
			}
		}
		//因为是一直保持，所以最终结果只打印最右下角即可
		printf("%d\n",dp[L1][L2]);
	}
	return 0;


}