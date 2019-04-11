#include<iostream>
using namespace std;

class IntArray
{
public:
	IntArray(int s = 0);
	IntArray(IntArray& arr);
	~IntArray();
	IntArray& operator=(IntArray& right);
	//������Ա����
	int& operator[](int i) {
		//��������
		//ֻ���ó�Ա�������أ���������Ԫ��������
		if (i >= 0 && i < Size) {
			return pArr[i];
		}
		else {
			cout << "i is out of index" << endl;
			return pArr[0];
		}
	}

	//NEW
	friend istream& operator>>(istream& ist, IntArray& a);
	friend ostream& operator<<(ostream& ost, IntArray& a);
private:
	int* pArr;  //�����׵�ַ
	int Size;    //�����С
};

IntArray::IntArray(int s)
{
	if (s >= 0)
		Size = s;
	else
		Size = 0;
	pArr = new int[s];
}

IntArray::IntArray(IntArray & arr)
{
	pArr = new int[arr.Size];
	Size = arr.Size;
	for (int i = 0; i < arr.Size; i++) {
		pArr[i] = arr.pArr[i];
	}
}

IntArray::~IntArray()
{
	delete[]pArr;
	pArr = 0;
}

IntArray& IntArray::operator=(IntArray & right)//��������ʱ
{
	if (this == &right)return *this;//�Ľ�:����Ƿ��������
	delete[]pArr;
	Size = right.Size;
	if (right.pArr) {
		pArr = new int[right.Size];
		Size = right.Size;
		for (int i = 0; i < right.Size; i++) {
			pArr[i] = right.pArr[i];
		}
	}
	return *this;//֧����������
}



istream& operator>>(istream& ist, IntArray& a) {
	for (int i = 0; i < a.Size; i++)
		ist >> a.pArr[i];

	return ist;//��������
}
ostream& operator<<(ostream& ost, IntArray& a) {
	for (int i = 0; i < a.Size; i++)
		ost << a.pArr[i]<<" "  ;//��'cout<<'Ӱ����չ��

	return ost;//��������
}

int main()
{
	IntArray ia(10), ib(5);
	IntArray ic = ia;//��������
	ib = ia;	//�������

	cin >> ia;
	cout << ia;

	return 0;
}