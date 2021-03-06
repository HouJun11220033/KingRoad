#include<stdio.h>
#include<vector>
using namespace std;
struct E{
	int next;
	int c;
};
vector<E> Edge[101];
bool mark[101];
int dis[101];

int main(){
	int n,m;
	int count=0;
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if (n == 0 && m == 0) break;
		//这一条很重要！！！必须先清空vector容器！！！
		for (int i = 1;i <= n;i ++) Edge[i].clear(); 
		for(int i=0;i<m;i++)
		{
			E temp;
			scanf("%d%d%d",&a,&b,&c);
			temp.next=b;
			temp.c=c;
			Edge[a].push_back(temp);
			temp.next=a;
			Edge[b].push_back(temp);
		}
		for(int i=1;i<=n;i++)
		{
			dis[i]=-1;
			mark[i]=false;
		}
		dis[1]=0;
		mark[1]=true;
		int newP=1;
		for(int i=1;i<n;i++)
		{
			//遍历i的所有边
			for(int j=0;j<Edge[i].size();j++)
			{
				int t=Edge[newP][j].next;
				int c=Edge[newP][j].c;

				if(mark[t]==true)
				{
					continue;
				}
				if(dis[t]==-1 || dis[t]>dis[newP]+c)
				{
					dis[t]=dis[newP]+c;
				}
				
			}
			int min = 123123123; //最小值初始化为一个大整数,为找最小值做准备
			for(int j=1;j<=n;j++)
			{
				if(mark[j]==true)
				{
					continue;
				}
				if(dis[j]==-1)
				{
					continue;
				}
				//所有不相邻的
				if(dis[j]<min)
				{
					min=dis[j];
					newP=j;
				}
			}
			mark[newP]=true;
		}
		printf("%d\n",dis[n]);		
	}
	return 0;
}