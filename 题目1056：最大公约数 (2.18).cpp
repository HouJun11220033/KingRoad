#include<stdio.h>
using namespace std;
int gcd(int a,int b){
	//һֱģ��ֱ��b����0
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
		ans=gcd(n,m);
		printf("%d\n",ans);
	}
	return 0;
}