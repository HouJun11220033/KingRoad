#include<iostream>
#include<vector>
#include <string>
#include <stdlib.h>
using namespace std;
int main(){
	vector<int> myvector;
	vector<int>::iterator p;
	for(int i=0;i<10;i++)
	{
		myvector.push_back(i);
	}
	p=myvector.end()-1;
	for(int i=0;i<10;i++)
	{
		cout<<"myvector["<<i<<"]::"<<myvector[i]<<"\n";
		cout<<"iterator P::"<<*p<<"\n";
		p--;
	}
	
	return 0;

}