#include<stdio.h>
#include<string.h>

//树结点结构体
struct Node{
	//左儿子指针
	Node *lchild;
	//右儿子指针
	Node *rchild;
	//结点字符信息
	char c;

}Tree[50];//静态内存分配数组
int loc;//静态数组中已经分配的结点个数
Node *create(){
	//创建一个节点
	Tree[loc].lchild=Tree[loc].rchild=NULL;
	return &Tree[loc++]; 
}
//分别保存前序和中序
char str1[30],str2[30];
//后序遍历
void postOrder(Node *T)
{
	//若左子树不为空
	if(T->lchild!=NULL)
	{
		postOrder(T->lchild);
	}
	//递归遍历其左子树
	if(T->rchild!=NULL)
	{
		postOrder(T->rchild);
	}
	printf("%c",T->c);
}

//还原二叉树,s1和e1表示先序遍历的开始和结束,s2和e2表示中序遍历的开始和结束
Node *build(int s1,int e1,int s2,int e2)
{
	//先创建根节点
	Node * ret=create();

	//为根节点赋值，该结点字符为前序遍历中第一个字符
	ret->c=str1[s1];
	//根节点下标
	int rootidx;
	//这个for循环用于找到在中序遍历里面的根节点
	for(int i=s2;i<=e2;i++)
	{
		if(str2[i]==str1[s1])
		{
			rootidx=i;
			break;
		}
	}
	//若左子树不为空
	if(rootidx != s2)
	{
		//两种形式的左子树
		ret->lchild=build(s1+1,s1+(rootidx-s2),s2,rootidx-1);
	}
	//若右子树不为空
	if(rootidx!=e2)
	{
		ret->rchild=build(s1+(rootidx-s2)+1,e1,rootidx+1,e2);
	}

	//返回根节点
	return ret;

	
}
int main(){
	while(scanf("%s",str1)!=EOF)
	{
		scanf("%s",str2);
		//初始化静态内存空间中已经使用结点个数为0
		loc=0;
		//计算两个字符串长度
		int L1=strlen(str1);
		int L2=strlen(str2);
		//还原整棵树,其根结点指针保存在T中
		Node *T=build(0,L1-1,0,L2-1);
		postOrder(T);
		printf("\n");
	}
	return 0;

}