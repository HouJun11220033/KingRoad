#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
struct Stu{
	char name[101];
	int age;
	int score;
	
}s[1000];
bool cmp(Stu a,Stu b){
	//两个字符串自左向右逐个字符相比（按ASCII值大小相比较
	
	if(a.score!=b.score)
	{
		return a.score<b.score;
	}
	int tmp=strcmp(a.name,b.name);
	if(tmp!=0)
	{
		return tmp<0;
	}else{
		//若名字也相同则年龄小者在前
			return a.age<b.age;
	}

}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			//scanf("%s%d%d",Stu[i].name,&Stu[i].age,&Stu[i].score);
			cin>>s[i].name>>s[i].age>>s[i].score;
		}
		sort(s,s+n,cmp);
		for(int i=0;i<n;i++)
		{
			//printf("%s%d%d",Stu[i].name,Stu[i].age,Stu[i].age);
			cout<<s[i].name<<" "<<s[i].age<<" "<<s[i].score<<endl;
		}
	}
	return 0;
}