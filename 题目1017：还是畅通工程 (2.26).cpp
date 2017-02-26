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
		//对每条边进行遍历
		for(int i=0;i<n*(n-1)/2;i++)
		{
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			//两个点属于不同的集合(父节点不同)
			//必须是属于不同集合的两个点，因为如果属于同一集合前面已经有比他小的权值在集合里面
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