#include<stdio.h>
using namespace std;
int gcd(int a,int b){
	//Ò»Ö±Ä££¬Ö±µ½bµÈÓÚ0
	if(b==0)
	{
		return a;
	}
	int temp;
	temp=b;
	b=a%b;
	a=temp;
	gcd(a,b);
}
int main(){
	int n,m,ans;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		//14%49=14!!!!
		ans=gcd(n,m);
		printf("%d\n",ans);
	}
	return 0;
}
