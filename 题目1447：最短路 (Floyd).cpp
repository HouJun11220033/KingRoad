//������ڵ�i������ڵ�j�����·�������2�ֿ��ܣ�
//1.��ֱ�Ӵ�i��j
//2.�Ǵ�i�������ɸ��ڵ�k��j
//���ԣ����Ǽ���Dis(i,j)Ϊ�ڵ�u���ڵ�v�����·���ľ��룬����ÿһ���ڵ�k�����Ǽ��Dis(i,k) + Dis(k,j) < Dis(i,j)�Ƿ����
//���������֤����i��k�ٵ�j��·����iֱ�ӵ�j��·���̣����Ǳ�����Dis(i,j) = Dis(i,k) + Dis(k,j)
//����һ���������Ǳ��������нڵ�k��Dis(i,j)�м�¼�ı���i��j�����·���ľ���
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
		//ѭ��kֵ������
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
						//��������ǰ�᣺��û���ϵ������ϣ��������Ƚϴ�С������˵��
						//1 i�ܵ�k ���� k�ܵ�j
						//2 i��k����k��j С��ԭ��i��j��ֵ
						ans[i][j]=ans[i][k]+ans[k][j];
					}

				}
			}
		}
		printf("%d\n",ans[1][n]);
	}
	return 0;
}