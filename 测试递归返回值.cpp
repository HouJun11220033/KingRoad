#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int add(int x)
{
	if(x>100)
	{
		return 0;
	}
	x++;
	add(x);
	return x;
}
int main()
{
	int i=1;
	int result=add(i);
	//�ݹ�ķ���ֵ��ֻ���ص�һ�ε����������ʱ�ķ���ֵ
	//�ڵݹ��У�����ÿ����һ��ֵ���������ջ�У���󷵻ص���ջ�׵�ֵ������
	//result=2;
	printf("%d\n",result);
	system("pause");
	return 0;
	
}