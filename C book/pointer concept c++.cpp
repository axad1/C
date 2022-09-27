#include<iostream>
using namespace std;
int main()
{
	int a=100,*p=&a;
	cout<<"Value of A "<<a<<endl;
	cout<<"Value of A through Pointer "<<*p<<endl;
	cout<<"Address of A "<<&a<<endl;
	cout<<"Address of A through Pointer "<<p<<endl;
	cout<<"Value of Pointer "<<p<<endl;
	cout<<"Address of Pointer "<<&p<<endl;
}
