#include <iostream>  //���� ʵ��ʱ��һ��ͷ�ļ���ʽ
#include <assert.h>
#include "stack.h"
using namespace std;

template <class T>
struct StackNode {                    //ջ����ඨ��

	T data;			          //ջ�������
	StackNode<T> *link;            //�����ָ��

	StackNode(T d = 0, StackNode<T> *next = NULL)
		: data(d), link(next) { }     //���캯��
};
template <class T>
class LinkedStack : public Stack<T> { //��ʽջ�ඨ��   
private:
	StackNode<T> *top;		            //ջ��ָ��
	static void output(ostream& os,
		StackNode <T> *ptr, int i);
	//�ݹ����ջ������Ԫ��
public:
	LinkedStack() : top(NULL) {}	   //���캯��
	~LinkedStack() { makeEmpty(); }   //��������
	void Push(T x);		             	   //��ջ
	bool Pop(T& x);			   //��ջ
	bool getTop(T& x) const;		//ȡջ��  	
	bool IsEmpty() const { return top == NULL; }
	bool IsFull() const { return false; }
	//˼��Ϊ��ֱ�ӷ���Ϊ��
	void makeEmpty();			//���ջ������

	friend ostream& operator << (ostream& os,
		LinkedStack<T>& s) //�̲�94ҳ����һ�ּ�ʵ��
	{
		cout << ��Show stack�� << endl;
		output(os, s.top, 0); return os;
	} //����ʵ��			//���ջԪ�ص����ز��� <<
};

template <class T>
void LinkedStack<T>::makeEmpty() {
	//���ɾȥ��ʽջ�е�Ԫ��ֱ��ջ��ָ��Ϊ�ա�
	StackNode<T> *p;
	while (top != NULL)		//�������ͷ�
	{
		p = top;  top = top->link;  delete p;
	}
};

template <class T>
void LinkedStack<T>::Push(T x) {
	//��Ԫ��ֵx���뵽��ʽջ��ջ��, ����ͷ��
	top = new StackNode<T>(x, top); //������x�½��
	assert(top != NULL);		         //����ʧ���˳�
};


template <class T>
bool LinkedStack<T>::Pop(T& x) {
	//ɾ��ջ�����, ���ر�ɾջ��Ԫ�ص�ֵ��
	if (IsEmpty() == true) return false;   //ջ�շ���
	StackNode<T> *p = top;		//�ݴ�ջ��ָ��
	top = top->link;			//��ջ��ָ��
	x = p->data;
	delete p;		                               //�ͷŽ��
	return true;
};
template <class T>
void LinkedStack<T>::output(ostream& os,
	StackNode<T> *ptr, int i) {
	//�ݹ����ջ������Ԫ�أ��������������
	if (ptr != NULL) {
		i++;
		if (ptr->link != NULL)
			output(os, ptr->link, i);   //�ݹ����
		os << i << �� : �� << ptr->data << endl;
		//������ջ��Ԫ�ص�ֵ   
	}   // ptr �ʼָ��ջ����i=0
};

template <class T>
bool LinkedStack<T>::getTop(T& x) const {
	if (IsEmpty() == true) return false;   //ջ�շ���
	x = top->data;                       //����ջ��Ԫ�ص�ֵ
	return true;
};
