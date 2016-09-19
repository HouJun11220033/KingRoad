#include<stdio.h>
#include<string>
#include<algorithm>
#define ISRUN(x) x%100 !=0 && x %4==0 || x % 400 == 0 ?1:0
using namespace std;
int dayOfmonth[13][2]={
0,0,
31,31,
28,29,
31,31,
30,30,
31,31,
30,30,
31,31,
31,31,
30,30,
31,31,
30,30,
31,31
};
struct Day{
	int y;
	int m;
	int d;
	//把方法写在结构体里面
	//注意年与年之间，月与月之间！！！
	void nextDay(){
		d++;
		if(d>dayOfmonth[m][ISRUN(y)])
		{
			d=1;
			m++;
			if(m>12)
			{
				m=1;
				y++;
			}
			
		}
	}
}day[101];

int buf[5001][13][32];
int Abs(int x)
{
	return x<0?-x:x;
}

int main(){
	Day tmp;
	int num1=0;
	int count=0;
	tmp.d=1;
	tmp.m=1;
	tmp.y=0;//初始化日期类对象为0年1月1日
	while(tmp.y!=5001)
	{
		buf[tmp.y][tmp.m][tmp.d]=count;
		tmp.nextDay();
		count++;
	}
	int d1 , m1 , y1;
	int d2 , m2 , y2;
	while (scanf ("%4d%2d%2d",&y1,&m1,&d1) != EOF) {
		scanf ("%4d%2d%2d",&y2,&m2,&d2); //读入要计算的两个日期
		//用预处理的数据计算两日期差值,注意需对其求绝对值
		printf("%d\n",Abs(buf[y2][m2][d2] - buf[y1][m1][d1]) + 1); 

	}
	return 0;
}