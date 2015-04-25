#define _CRT_SECURE_NO_WARNINGS
#ifndef ASTRING_H	//�������ļ���Astring.h����
#define ASTRING_H
#include <string>
#include <iostream>
using namespace std;
class AString {
	//����: ��������ַ���һ���������С�
private:
	char *ch;			      //���������
	int curLength;		      //����ʵ�ʳ���
	int maxSize;		      //����������󳤶�
public:
	AString(int sz = 128);  //���캯��  ����һ���մ�
	AString(const char *init);  //���캯���������ַ�����*init����
	AString(const AString& ob); //���ƹ��캯�������д�ob����
	~AString() { delete []ch; }	      //��������
	int Length() const { return curLength; }	 //�󳤶�
	AString& operator() (int pos, int len);   //���Ӵ�
	bool operator == (AString& ob) const
	{
		return strcmp(ch, ob.ch) == 0;
	}
	//�д����. �������, ��������true
	bool operator != (AString& ob) const
	{
		return strcmp(ch, ob.ch) != 0;
	}
	//�д�����. ���������, ��������true  
	bool operator ! () const { return curLength == 0; }
	//�д��շ�������, ��������true
	AString& operator = (AString& ob);      //����ֵ
	AString& operator += (AString& ob);	//������
	char operator [] (int i);		//ȡ�� i ���ַ�
	int Find(AString& pat, int k) const;     	//��ƥ��
};

AString::AString(const char *init) {
	//���ƹ��캯��: �������ַ�����*init����
	int len = strlen(init);
	maxSize = (len > 128) ? len : 128;
	ch = new char[maxSize + 1];     //����������
	if (ch == NULL)
	{
		cerr << "�洢����� !\n";  exit(1);
	}
	curLength = len;	 	   //���ƴ�����
	strcpy(ch, init);		             //���ƴ�ֵ	
};

AString::AString(const AString& ob) {
	//���ƹ��캯���������д�ob����
	maxSize = ob.maxSize;               //���ƴ���󳤶�
	ch = new char[maxSize + 1];   //����������
	if (ch == NULL)
	{
		cerr << "�洢�����!\n";  exit(1);
	}
	curLength = ob.curLength;          //���ƴ�����
	strcpy(ch, ob.ch);                         //���ƴ�ֵ
};

AString& AString::operator = (AString& ob) {
	if (&ob != this) {	//�����������Ϊ���Ҹ�ֵ
		delete []ch;
		ch = new char[ob.maxSize + 1];  //P160�޸� 
		if (ch == NULL)
		{
			cerr << "�洢����ʧ��!\n";  exit(1);
		}
		curLength = ob.curLength;  strcpy(ch, ob.ch);
	}
	else cout << "�ַ�������ֵ����!\n";
	return *this;
};

char AString::operator [] (int i) {
	//�����ز�����ȡ��ǰ��*this�ĵ�i���ַ�
	if (i < 0 || i >= curLength)    
	{
		cout << "�ַ����±곬��!\n"; exit(1);
	}
	return ch[i];
};

#endif