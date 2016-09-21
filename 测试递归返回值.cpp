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
	//递归的返回值：只返回第一次调用这个函数时的返回值
	//在递归中，函数每返回一个值，都会放入栈中，最后返回的是栈底的值！！！
	//result=2;
	printf("%d\n",result);
	system("pause");
	return 0;
	
}