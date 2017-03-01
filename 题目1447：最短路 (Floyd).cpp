//从任意节点i到任意节点j的最短路径不外乎2种可能，
//1.是直接从i到j
//2.是从i经过若干个节点k到j
//所以，我们假设Dis(i,j)为节点u到节点v的最短路径的距离，对于每一个节点k，我们检查Dis(i,k) + Dis(k,j) < Dis(i,j)是否成立
//如果成立，证明从i到k再到j的路径比i直接到j的路径短，我们便设置Dis(i,j) = Dis(i,k) + Dis(k,j)
//这样一来，当我们遍历完所有节点k，Dis(i,j)中记录的便是i到j的最短路径的距离
#include<stdio.h>
using namespace std;
int ans[101][101];
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF && n!=0 && m!=0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				ans[i][j]=-1;
			}
			//ans[i][i]=0;
		}
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			ans[a][b]=ans[b][a]=c;

		}
		//循环k值！！！
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(ans[i][k]==-1 || ans[k][j]==-1)
					{
						continue;
					}
					if(ans[i][j]==-1 || ans[i][k]+ans[k][j]<ans[i][j])
					{
						//这样做的前提：（没连上的先连上！！！，比较大小连上再说）
						//1 i能到k 而且 k能到j
						//2 i到k加上k到j 小于原先i到j的值
						ans[i][j]=ans[i][k]+ans[k][j];
					}

				}
			}
		}
		printf("%d\n",ans[1][n]);
	}
	return 0;
}