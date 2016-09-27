#include<stdio.h>
using namespace std;
#define N 1000
int Tree[N];

//����ĳ������������ĸ����
//���룺�ڵ�ֵ
//���أ�1.���������Ǹ��ڵ�-->�ڵ�ֵ
//      2.��������Ǹ��ڵ㣬����õݹ麯������󷵻ص����������ĸ��ڵ㣡����
int findRoot(int x)
{
	if(Tree[x]==-1)
	{
		return x;
	}else
	{
		//ѹ��·��
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int main(){
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
		{
			//��ʼʱ,���н�㶼�ǹ����ļ���,�������ڼ���ֻ��һ�����,�䱾����������������

			Tree[i]=-1;
		}
		while(m--!=0)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			//���ұߵ������������ڼ�����Ϣ
			a=findRoot(a);
			b=findRoot(b);
			//��һ��ѭ��ʱ��a���Ѿ�������b�ˣ�����Ҫ�ϲ�������
			
			if(a!=b)
			{
				Tree[a]=b;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			//ͳ�����н���и����ĸ���
			if(Tree[i]==-1)
			{
				ans++;
			}
		}
		//�𰸼�Ϊ��ans�����ϼ����޽�ans-1����·����ʹ���н����ͨ
		//ֻҪ����һ���ڵ㣨һ�����ϣ���������󼯺ϣ�������ͨ�˴������

		printf("%d\n",ans-1);
	}

}