#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int Tree[101];
struct Node{
	double x;
	double y;
	double getDis(Node a,Node b)
	{
		double tmp=(a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
		return sqrt(tmp);
	}
}list[101];

struct Edge{
	int a,b;
	double cost;
}edge[6000];
bool cmp(Edge a,Edge b)
{
	return a.cost<b.cost;
}

void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		Tree[i]=-1;
	}
}

int findRoot(int x){
	if(Tree[x]==-1)
	{
		return x;
	}else
	{
		int temp=findRoot(Tree[x]);
		Tree[x]=temp;
		return temp;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		init(n);
		for(int i=1;i<=n;i++)
		{
			double a,b;
			scanf("%lf%lf",&a,&b);
			list[i].x=a;
			list[i].y=b;
		}
		int size=0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				edge[size].a=i;
				edge[size].b=j;
				edge[size].cost=list[i].getDis(list[i],list[j]);
				size++;
			}
		}
		sort(edge,edge+size,cmp);
		double ans=0;
		for(int i=0;i<size;i++)
		{
			int a=findRoot(edge[i].a);
			int b=findRoot(edge[i].b);
			if(a!=b)
			{
				Tree[a]=b;
				ans+=edge[i].cost;
			}
		}
		printf("%.2lf\n",ans);
	}

	return 0;
}