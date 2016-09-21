#include<stdio.h>
#include<queue>
using namespace std;
bool mark[50][50][50];//标记数组
int maze[50][50][50];
struct N{  //状态结构体
	int x,y,z;
	int t;

};
queue<N> Q; //队列，队列中的元素为状态
int go[][3]={     //坐标变换数组，由坐标(x,y,z)扩展得到新坐标俊可以通过(x+go[i][0],y+go[i][1],z+go[i][2])得到
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
int BFS(int a,int b,int c)//广度优先搜索，返回其最少耗时
{
	while(Q.empty()==false) //当队列中仍有元素可以扩展时候循环
	{
		N now=Q.front(); //获得队头状态
		Q.pop();//弹出对头状态
		for(int i=0;i<6;i++)//依次扩展其六个节点
		{
			int nx = now.x + go[i][0];
			int ny = now.y + go[i][1];
			int nz = now.z + go[i][2];
			if(nx<0 || nx>=a || ny <0 || ny>=b ||nz<0 || nz>=c)
			{
				continue;
			}
			if(maze[nx][ny][nz]==1)//若该位置为“墙”，则丢弃该坐标
			{
				continue;
			}
			if(mark[nx][ny][nz]==true)
			{
				continue;
			}
			N tmp; //新的状态
			tmp.x=nx;
			tmp.y=ny;
			tmp.z=nz; 
			tmp.t=now.t+1; //新状态的耗时
			Q.push(tmp); //将该状态放入队列
			mark[nx][ny][nz]=true; //标记该坐标
			if(nx==a-1 && ny==b-1 && nz==c-1)
			{
				return tmp.t; //若该坐标即为终点，可直接返回其耗时
			}
			
		}
		
	}
	return -1;

}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,t;
		scanf("%d%d%d%d",&a,&b,&c,&t);
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				for(int k=0;k<c;k++)
				{
					scanf("%d",&maze[i][j][k]);
					mark[i][j][k]=false;
				}
			}
		}
		while(Q.empty()==false)
		{
			Q.pop();
		}
		mark[0][0][0]=true;
		N tmp;
		tmp.t=tmp.y=tmp.x=tmp.z=0;
		Q.push(tmp);
		int rec=BFS(a,b,c);
		if(rec<=t)
		{
			printf("%d\n",rec);
		}else
		{
			printf("-1\n");
		}
	
	}
	return 0;
}