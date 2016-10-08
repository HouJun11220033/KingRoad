#include<stdio.h>
#include<string.h>

struct bigInteger
{
	int digit[1000];
	int size;
	void init(){
		for(int i=0;i<1000;i++)
		{
			digit[i]=0;
		}
		size=0;
		
	}
	void set(char str[]){
		init();
		int length=0;
		int weight=1;
		int temp,sum_temp=0;
		for(int i=strlen(str)-1,j=0,t=0,c=1;i>=0;i--)
		{
			t+=(str[i]-'0')*c;
			j++;
			c*=10;
			if(j==4 || i==0)
			{
				digit[size++]=t;
				j=0;
				t=0;
				c=1;
			}

		}

	}
	void output(){
		//���digit����
		for(int i=size-1;i>=0;i--)
		{
			if(i!=size-1)
			{
				//����ǰ��������ֲ�
				//�����λ����,��%04�����ǰ��0,����ǰ���ֲ���4λʱ��0����,�����110001�ĺ���λ��
				printf("%04d",digit[i]);
			}
			else{
				printf("%d",digit[i]);
			}
		}
		printf("\n");
	}
	bigInteger operator + (const bigInteger &A) const
	{
		bigInteger result;
		result.init();
		int carry=0;
		for(int i=0;i<A.size||i<size;i++)
		{
			int temp=A.digit[i]+digit[i]+carry;
			carry=temp/10000;
			temp%=10000;
			result.digit[result.size++]=temp;
		}
		if(carry!=0)
		{
			result.digit[result.size++]=carry;
		}
		return result;
		
	}


}a,b,c;
char input_a[1001];
char input_b[1001];
int main()
{
	
	while(scanf("%s%s",input_a,input_b)!=EOF)
	{
		a.set(input_a);
		b.set(input_b);
		c=a+b;
		c.output();
	}
	return 0;

}