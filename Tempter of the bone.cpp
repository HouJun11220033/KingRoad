//深搜+剪枝（奇偶剪枝）
#include<stdio.h>
#include<stdlib.h>
using namespace std;
char maze[8][8];
int n,m,t;
bool success;
int go[][2]={
	1,0,
	-1,0,
	0,1,
	0,-1,
};
void DFS(int x,int y,int time)
{
	for (int i = 0;i < 4;i ++) { //枚举四个相邻位置
	int nx = x + go[i][0];
	int ny = y + go[i][1]; //计算其坐标
	//!!!!!!更改for循环里面的东西，这里也要记得改！！！！
	if (nx < 1 || nx > n || ny < 1 || ny > m) continue; //若坐标在地图外跳过

	if (maze[nx][ny] == 'X') continue; //若该位置为墙,跳过
	if (maze[nx][ny] == 'D') {				 //若该位置为门
		if (time + 1== t) {	//若所用时间恰好为t
		success = true; //搜索成功
		return; //返回
	}
	else continue; //否则该状态的后续状态不可能为答案(经过的点不能再经过),过
			
	}
	maze[nx][ny] = 'X'; //该状态扩展而来的后续状态中,该位置都不能被经过,直接修该位置为墙

	DFS(nx,ny,time + 1); //递归扩展该状态,所用时间递增
	maze[nx][ny] = '.'; //若其后续状态全部遍历完毕,则退回上层状态,将因为要搜索后续状态而改成墙的位置,改回普通位置

	if (success) return;//假如已经成功,则直接返回,停止搜索
	}
}
int main(){
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		if(n==0 && m==0 && t==0)
		{
			break;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",maze[i]);
		}
		success=false;
		int sx,sy;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(maze[i][j]=='D')
				{
					sx=i;
					sy=j;
				}
			}
		}

		for(int i=0;i<n;i++)
		{
			for (int j = 0;j < m;j ++)
			{
				//剪枝
				if(maze[i][j] == 'S' && (i + j) % 2 ==  ( (sx + sy) % 2 + t %2 ) % 2) 

				{
					maze[i][j]='X';
					DFS(i,j,0);
				}
				
			}
		}
		puts(success==true ?"YES":"NO");
		system("pause");
	}
	return 0;
}
