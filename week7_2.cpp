#include<iostream>
using namespace std;

class IntArray
{
public:
	IntArray(int s = 0);
	IntArray(IntArray &arr);
	~IntArray();
	IntArray& operator=(IntArray& right);
	//������Ա����
	//int getV(int i);
	int &operator[](int i) {
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
	//bool setVAlue(int i, int x) {
	//	if (i >= 0 && i < Size) {
	//		pArr[i] = x;
	//		return true;
	//	}
	//	else return false;
	//}
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

IntArray::IntArray(IntArray& arr)
{
	pArr = new int[arr.Size];
	Size = arr.Size;
	for (int i = 0; i < arr.Size; i++) {
		 pArr[i] =arr.pArr[i];
	}
}

IntArray::~IntArray()
{
	delete[]pArr;
	pArr = 0;
}

IntArray &IntArray::operator=(IntArray& right)//��������ʱ
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

//int IntArray::getV(int i)
//{
//	if (i >= 0 && i < Size) {
//		return pArr[i] ;
//	}
//	else {
//		cout << "i is out of index"<<endl;
//		return pArr[0];
//	}
//}

int main()
{
	IntArray ia(10), ib(5);
	IntArray ic= ia;//��������
	ib = ia;	//�������
	for (int i = 0; i < 3; i++) {
		cin >> ia[i];
	}
	//ib = ia;//ϵͳ�Դ�:b.Size=a.Size;b.pArr=a.pArr;
	ic = ib = ia;
	//ia = ia;
	cout << ib[0]<<endl;
	cout << ic[2];
	return 0;
}