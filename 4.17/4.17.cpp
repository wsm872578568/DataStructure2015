#include <iostream>
#include "LinkStr.h"
using namespace std;

int main(){
	List a,b,sub;
	string str1, str2,str3;
	str1 = "1234";
	str2 = "1234";
	str3 = "23";
	a.data(str1);
	b.data(str2);
	sub.data(str3);
	cout << "���ȣ�" << a.Length() << ' ' << b.Length() << endl;
	int equal = (a == b);
	cout << "�ж���ȣ�" << equal<<endl;
	a.Find(2, 2, sub);
	cout << "����Ӵ���"; 
	sub.output(); cout << endl;
	cout << "����ϳɴ���";
	if (a + b){ a.output(); }
	cout << endl;
	cout<<"�Ӵ�λ�ã�"<<b.subLocate(sub);
	cout << endl;
}