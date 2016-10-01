#include<stdio.h>
#include<stdlib.h>
// 定义宏判断是否是闰年，方便计算每月天数
#define isLeap(x) x%100 !=0 && x%4==0 || x%400==0 ?1:0
int dayOfMonth[13][2]={
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
void nextdate(int year,int month,int day)
{
	//isLeap(year);
	//计算day
	//day++;
	//从日开始判断！！！！！
	if(day<dayOfMonth[month][isLeap(year)])
	{
		day++;
		printf("Year:%d-Month:%d-Day:%d",year,month,day);
		
		
	}else if(day>=dayOfMonth[month][isLeap(year)])
	{
		day=1;
		month++;
		if(month>12)
		{
			month=1;
			year++;
			printf("Year:%d-Month:%d-Day:%d",year,month,day);
		}else
		{
			printf("Year:%d-Month:%d-Day:%d",year,month,day);
		}

	}


	//计算month
	
	
}
int main(){
	int y,m,d;
	while(scanf("%d%d%d",&y,&m,&d)!=EOF)
	{
		nextdate(y,m,d);
	}

	return 0;
}