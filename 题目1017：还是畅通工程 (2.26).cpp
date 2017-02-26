#include<stdio.h>
#include<algorithm>
using namespace std;
struct Edge{
	int a;
	int b;
	int cost;
}edge[9999];
int Tree[100];
int findRoot(int x){
	if(Tree[x]==-1)
	{
		return x;
	}else{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
}
bool cmp(Edge a,Edge b)
{
	return a.cost<b.cost;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		for(int i=1;i<=n;i++)
		{
			Tree[i]=-1;
		}
		for(int i=0;i<(n*(n-1))/2;i++)
		{
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
		}
		sort(edge,edge+((n*(n-1))/2),cmp);
		int ans=0;
		//��ÿ���߽��б���
		for(int i=0;i<n*(n-1)/2;i++)
		{
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			//���������ڲ�ͬ�ļ���(���ڵ㲻ͬ)
			//���������ڲ�ͬ���ϵ������㣬��Ϊ�������ͬһ����ǰ���Ѿ��б���С��Ȩֵ�ڼ�������
			if(a!=b)
			{
				Tree[a]=b;
				ans+=edge[i].cost;
			}

		}
		printf("%d\n",ans);
	}
	return 0;
}