template <class T>
class Stack {			//ջ���ඨ��
public:
	Stack(){ };			//���캯��
	virtual void Push(T x) = 0;             //��ջ
	virtual bool Pop(T& x) = 0;	     //��ջ
	virtual bool getTop(T& x)const = 0; //ȡջ��
	virtual bool IsEmpty()const = 0;	     //��ջ��
	virtual bool IsFull()const = 0;	     //��ջ��
};