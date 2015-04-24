#include <iostream>
#include <string.h>
using namespace std;
struct LinkNode {	 	       //��������Ķ��� !!
	char data;			       //������
	LinkNode *link;     //��ָ����
	LinkNode() { link = NULL; }    //���캯��, ��������
	LinkNode(char& item, LinkNode *ptr = NULL)
	{
		data = item;  link = ptr;
	}     //���캯��, ������
	bool operator == (char x) { return data == x; }
	bool operator != (char x) { return data != x; }
};

class List {

protected:
	LinkNode *first;
public:
	List() { first = new LinkNode; }  //���캯��
	List(char x) { first = new LinkNode(x); } //������
	List(List& L);		//���ƹ��캯��
	~List(){ }				//��������

	int Length() const;
	LinkNode *Search(char x);	    //������xԪ�� 
	LinkNode *Locate(int i);    //��λ��i��Ԫ��
	bool getData(int i, char& x); //ȡ����i��Ԫ��ֵ
	void setData(int i, char& x);	    //���µ�i��Ԫ��ֵ
	bool Insert(int i, char& x);           //�ڵ�i��Ԫ�غ����
	bool Remove(int i, char& x);	    //ɾ����i��Ԫ��
	bool IsEmpty() const 		    //�б�շ�
	{
		return first->link == NULL ? true : false;
	}
	void data(string str);
	LinkNode *getFirst() const { return first; }
	List& Find(int location, int length,List& substr);
	int subLocate(List& substr);
	
	bool operator==(List& L);
	bool operator+(List& L);
	void output();
};
//���
void List::output(){
	LinkNode *p = first->link;
	while (p != NULL){
		cout << p->data;
		p = p->link;
	}
}
//��λ
LinkNode* List::Locate(int i){
	LinkNode* current = first; int k = 0;
	while (current != NULL&&k < i){
		current = current->link;
		k++;
	}
	return current;
}
//ȡֵ
bool List::getData(int i, char& x){
	LinkNode* p = Locate(i);
	x = p->data;
	return true;
}
//�趨ֵ
void List::setData(int i, char& x){
	LinkNode* p = Locate(i);
	p->data=x;
}
//���㳤��
int List::Length() const{
	LinkNode* p = first->link;
	int count = 0;
	while (p != NULL){
		p = p->link;
		count++;
	}
	return count;
}
//��ֵ
void List::data(string a){
	LinkNode* newNode;
	int flag = 0;
	int l = a.length();
	while (flag<l){
		newNode = new LinkNode(a[l-flag-1]);
		newNode->link = first->link;
		first->link = newNode;
		flag++;
	}
}
//�ж����
bool List::operator==(List& L){
	LinkNode *p, *q;
	p = first;
	q = L.getFirst();
	int flag = 0;
	while (p->link != NULL&&q->link != NULL){
		if (p->link->data != q->link->data) break;
		p = p->link;
		q = q->link;
	}
	if (p->link == NULL&&q->link == NULL) return 1;
	else return 0;
}
//����
bool List::operator+(List& L){
	LinkNode* p = first->link;
	while (p ->link != NULL){
		p = p->link;
	}
	LinkNode* q = L.getFirst();
	LinkNode* newNode;
	while (q->link != NULL){
		newNode = new LinkNode(q->link->data);
		p->link = newNode;
		p = newNode;
		q = q->link;
	}
	return true;
}
//���Ӵ�
List& List::Find(int location, int length,List& substr){
	LinkNode* p = Locate(location);
	LinkNode* current = substr.getFirst();
	
	int count = 1;
	while (count < length+1){
		current -> link = new LinkNode(p->data);
		
		p = p->link;
		current = current->link;
		count++;
	}
	return substr;
}
//���Ӵ��ڴ��е�λ��
int List::subLocate(List& substr){
	int i, j;LinkNode* p, *q;
	int l1 = Length(); int l2 = substr.Length();
	for (i = 0; i <= l1 - l2; i++){
		for (j = 1; j < l2; j++){
			
			p = Locate(i + j);
			q = substr.Locate(j);
			if (p->data != q->data) break;
		}
		if (j == l2) return i+1;
	}
	return -1;
}



