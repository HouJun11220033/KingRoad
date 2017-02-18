//题目描述：
//    输入一系列整数，建立二叉排序数，并进行前序，中序，后序遍历。
//输入：
//    输入第一行包括一个整数n(1<=n<=100)。
//    接下来的一行包括n个整数。
//输出：
//    可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。
//    每种遍历结果输出一行。每行最后一个数据之后有一个空格。
//样例输入：
//5
//1 6 5 9 8
//样例输出：
//1 6 5 9 8 
//1 5 6 8 9 
//5 8 9 6 1 
//提示：
//输入中可能有重复元素，但是输出的二叉树遍历序列中重复元素不用输出。
#include<stdio.h>
#include<string.h>
struct Node{
	Node *lchild;
	Node *rchild;
	int c;//保存数字
}Tree[110];//静态数组
//防止覆盖，用loc
int loc;
//创建节点函数
Node *create(){
	//申请一个结点空间（地址）,返回指向其的指针
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++];
}
//后序遍历
void postOrder(Node *T){
	if(T->lchild!=NULL)
	{
		postOrder(T->lchild);
	}
	if(T->rchild!=NULL)
	{
		postOrder(T->rchild);
	}
	printf("%d ",T->c);

}
//中序遍历
void inOrder(Node *T)
{
	if(T->lchild!=NULL)
	{
		inOrder(T->lchild);
	}

	
	printf("%d ",T->c);
	
	if(T->rchild!=NULL)
	{
		inOrder(T->rchild);
	}
	
	
}
//前序遍历
void preOrder(Node *T)
{

	printf("%d ",T->c);
	if(T->lchild!=NULL)
	{
		preOrder(T->lchild);
	}

	if(T->rchild!=NULL)
	{
		preOrder(T->rchild);
	}
	
}

//往这个函数里面传入：一个节点地址！！！（也就是要插入的地方），和节点的值
//返回根结点指针
Node *Insert(Node *T,int x){
	//若当前树为空！！！（从这里可以看出，T里面是层层嵌套的，也就是说整个树在根节点T里面）
	if(T==NULL)
	{
		//T本来就是一个地址,所以返回值也要是一个地址
		T=create();
		T->c=x;
		return T;//返回根结点指针
	}else if(x<T->c)
	{
		T->lchild=Insert(T->lchild,x);
	}else if(x>T->c)
	{
		T->rchild=Insert(T->rchild,x);
	}
	return T;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		loc=0;
		Node *T=NULL;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			T=Insert(T,x);
		}
		preOrder(T); //前序遍历
		printf("\n"); //输出空行
		inOrder(T); //中序遍历
		printf("\n");
		postOrder(T); //后序遍历
		printf("\n");
	}
	return 0;

}


