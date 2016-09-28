#include<stdio.h>
#include<algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1)
	{
		return x;
	}
	else
	{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
struct Edge{
	int a,b;
	int cost;
	
}edge[6000];

// 放外面！！！以自己可以理解的方式写代码

bool cmp(Edge e1,Edge e2){
		return e1.cost<e2.cost;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		for(int i=1;i<=n*(n-1)/2;i++)
		{
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
		}
		sort(edge+1,edge+1+n*(n-1)/2,cmp);
		for(int i=1;i<=n;i++)
		{
			Tree[i]=-1;
		}
		int ans=0;
		for(int i=1;i<=n*(n-1)/2;i++)
		{
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			if(a!=b)
			{
				Tree[a]=b;
				ans+=edge[i].cost;
			}
		}
		printf("%d\n",ans);
	}

	
}
