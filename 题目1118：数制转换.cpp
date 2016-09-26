#include<stdio.h>
#include<string.h>
int main(){
	int a,b;
	char str[40];
	while(scanf("%d%s%d",&a,str,&b)!=EOF)
	{

		//tmp为我们将要计算的a进制对应的十进制数
		//lenth为字符串长度方便我们从低位到高位遍历每个数位上的数
		//c为各个数位的权重初始化为1,表示最低位数位权重为1,之后每位权重都是前一位权重的a倍
		int tmp=0,lenth=strlen(str),c=1;
		for(int i=lenth-1;i>=0;i--)
		{
			//从低位到高位遍历每个数位上的数
			int x;
			if(str[i]>='0' && str[i]<='9')
			{
				//当字符在0到9之间,计算其代表的数字
				x=str[i]-'0';
			}else if(str[i]>='a' && str[i]<='z')
			{
				//当字符为小写字母时,计算其代表的数字
				//就是十进制！！！！
				//但并不是个位，十位，百位啥的。。。
				x=str[i]-'a'+10;
			}else
			{
				//当字符为大写字母时,计算其代表的数字
				x=str[i]-'A'+10;
			}
			//以上步骤中，我只是求出了在其他进制中，从低位到高位，每一位所代表的十进制数字，然并卵，还需要权重c和进制数a的配合求出真正的十进制数！！！
			//累加该位数字与该数位权重的积
			tmp+=x*c;
			//计算下一位权重
			c*=a;

		}
		char ans[40],size=0;
		do{
			int x=tmp%b;
			ans[size++]=(x<10)?x+'0':x-10+'A';
			tmp/=b;
		}while(tmp);
		for(int i=size-1;i>=0;i--)
		{
			printf("%c",ans[i]);
		}
	}
}