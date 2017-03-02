#include<stdio.h>
#include<vector>
using namespace std;
struct Edge{
	int next;
	int c;
	int w;
};
vector<Edge> E[1001];
bool mark[1001];
int dis[1001];
int cost[1001];
int main(){
	int n,m,s,t;

	while(scanf("%d%d",&n,&m)!=EOF && n!=0 && m!=0)
	{

		for(int i=1;i<=n;i++)
		{
			E[i].clear();
			mark[i]=false;
			dis[i]=-1;
		}
		while(m--)
		{
			int a,b,d,p;
			scanf("%d%d%d%d",&a,&b,&d,&p);
			Edge temp;
			temp.next=b;
			temp.c=d;
			temp.w=p;
			E[a].push_back(temp);
			temp.next=a;
			E[b].push_back(temp);
		}
		scanf("%d%d",&s,&t);
		dis[s]=0;
		mark[s]=true;
		int newP=s;
		//������
		for(int i=1;i<n;i++)
		{
			//������
			for(int j=0;j<E[newP].size();j++)
			{
				if(mark[E[newP][j].next]==true) continue;
				//������жϷ�Ϊ���֣�
				//1.�����ڵ㻹δ����
				//2.�����ڵ��Ѿ����������Ǽ���newP��ԭ���Ķ�
				//3.����newP��ԭ��һ����ѡ��۸���͵�
				if(dis[E[newP][j].next]==-1 || dis[E[newP][j].next]>dis[newP]+E[newP][j].c || dis[E[newP][j].next]==dis[newP]+E[newP][j].c && cost[E[newP][j].next]>cost[newP]+E[newP][j].w)
				{
					dis[E[newP][j].next]=dis[newP]+E[newP][j].c;
					cost[E[newP][j].next]=cost[newP]+E[newP][j].w;
				}
			}
			int min=123123123;
			//������ȷ��newP
			for(int j=1;j<=n;j++)
			{
				if(mark[j]==true) continue;
				if(dis[j]==-1) continue;
				if(dis[j]<min)
				{
					min=dis[j];
					newP=j;
				}
			}
			mark[newP]=true;
		}
		printf("%d %d\n",dis[t],cost[t]);

	}
	return 0;
}
