#include<stdio.h>
using namespace std;
int n,m,t;
char maze[8][8];
bool success=false;
int go[][2]={1,0,-1,0,0,1,0,-1};
void DFS(int y,int x,int time){
	for(int i=0;i<4;i++){
		int nx=x+go[i][0];
		int ny=y+go[i][1];
		//x只
		if(nx<0 || nx>n-1 || ny>m-1 || ny<0)continue;
		if(maze[ny][nx]=='X')continue;
		if(maze[ny][nx]=='D')
		{
			if(time+1==t)
			{
				success=true;//成功之后还没玩完！还得一层一层返回
				return;
			}else continue;
		}
		maze[ny][nx]='X';
		//time++;
		DFS(ny,nx,time+1);
		maze[ny][nx]='.';
		//time--;
		if(success)return;//直到这里收到。。。才是最终的返回
	}

}
int main(){
	while(scanf("%d%d%d",&m,&n,&t)!=EOF && n!=0 && m!=0 && t!=0)
	{
		success = false;
		for(int i=0;i<m;i++)
		{
			scanf("%s",maze[i]);
		}
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				//maze[y][x];
				if(maze[i][j]=='S')
				{
					//起始点设为X
					maze[i][j]='X';
					DFS(i,j,0);
				}
			}
		}
		puts(success==true ?"YES":"NO");		
	}

	//	int;
	return 0;
}