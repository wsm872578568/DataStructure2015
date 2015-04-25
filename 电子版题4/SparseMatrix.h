#include <iostream>
#include <stdlib.h>
using namespace std;
template<class E>
struct Triple {               //��Ԫ����
	int row, col;	       //����Ԫ���к�/�к�
	E value;                   //����Ԫ�ص�ֵ
	Triple<E>& operator = (Triple<E>& R) //��㸳ֵ  
	{
		row = R.row;  col = R.col;  value = R.value;
	}
	//Triple<E>(int r, int c, E v){
		//row = r; col = c; value = v;
	//}
};

template <class E>
class SparseMatrix {
public:
	SparseMatrix(int Rw, int Cl, int Tm);                   //���캯��
	~SparseMatrix() { delete []smArray; }  //��������
	void Transpose(SparseMatrix<E>& B);    //ת��
	void Multiply(SparseMatrix<E>& b);
	void initialize(int i, int row, int col, int value){
		smArray[i].row = row;
		smArray[i].col = col;
		smArray[i].value = value;
	}
	void display(){
		for (int j = 0; j<Terms; j++){
			cout << smArray[j].row << ' '
				<< smArray[j].col << ' '
				<< smArray[j].value << ' '
				<< endl;
		}
	}
private:
	int Rows, Cols, Terms;        //�У��У�����Ԫ����
	Triple<E> *smArray;          //��Ԫ���
};

template <class E>
SparseMatrix<E>::SparseMatrix(int Rw, int Cl, int Tm) {
	Rows = Rw;   Cols = Cl;   Terms = Tm;
	smArray = new Triple<E>[Terms];          //��Ԫ���
	if (smArray == NULL) {
		cerr << "�洢����ʧ�ܣ�"<< endl;  exit(1);
	}
};

template <class E>
void SparseMatrix<E>::Transpose(SparseMatrix<E>& B) {
	int *rowSize = new int[Cols];       //��Ԫ��������
	int *rowStart = new int[Cols];      //ת��λ������
	B.Rows = Cols;   B.Cols = Rows;
	B.Terms = Terms;
	if (Terms > 0) {
		int i, j;
		for (i = 0; i < Cols; i++) rowSize[i] = 0;
		for (i = 0; i < Terms; i++)
			rowSize[smArray[i].col]++; //ԭ������з���Ԫ����
		rowStart[0] = 0;
		for (i = 1; i < Cols; i++)
			rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
		for (i = 0; i < Terms; i++) {
			j = rowStart[smArray[i].col];
			//��i������Ԫ�ھ���B��Ӧ�ŵ�λ��	
			B.smArray[j].row = smArray[i].col;    //����
			B.smArray[j].col = smArray[i].row;
			B.smArray[j].value = smArray[i].value;
			rowStart[smArray[i].col]++; //�޸ĸ���Ӧ��λ��
		}
	}
}

template <class E>
void SparseMatrix<E>::Multiply(SparseMatrix<E>& b) {
	SparseMatrix<E> result(Rows, b.Cols,Rows*b.Cols);
	int* rowsize = new int[b.Rows];
	int* rowstart = new int[b.Rows + 1];
	E* temp = new E[b.Cols];
	int i, current, lastinresult, rowA, colA, colB;

	for (i = 0; i < b.Rows; i++) { rowsize[i] = 0; }

	for (i = 0; i < b.Terms; i++) { rowsize[b.smArray[i].row]++; }

	rowstart[0] = 0;
	for (i = 1; i <= b.Rows; i++)
		rowstart[i] = rowstart[i - 1] + rowsize[i - 1];

	current = 0; lastinresult = -1;

	while (current < Terms){
		rowA = smArray[current].row;
		for (i = 0; i < b.Cols; i++) temp[i] = 0;
		while (current < Terms && smArray[current].row == rowA){
			colA = smArray[current].col;
			for (i = rowstart[colA]; i < rowstart[colA + 1]; i++){
				colB = b.smArray[i].col;
				temp[colB] += smArray[current].value*b.smArray[i].value;
			}
			current++;
		}
		for (i = 0; i < b.Cols; i++)
			if (temp[i] != 0){
				lastinresult++;
				result.smArray[lastinresult].row = rowA;
				result.smArray[lastinresult].col = i;
				result.smArray[lastinresult].value = temp[i];
			}
	}
	result.Rows = Rows; result.Cols = b.Cols;
	result.Terms = lastinresult + 1;
	delete []rowsize; delete []rowstart;delete []temp;
	for (int j = 0; j<result.Terms; j++){
		cout << result.smArray[j].row << ' '
			<< result.smArray[j].col << ' '
			<< result.smArray[j].value << ' '
			<< endl;
	}

}

	
