#include<iostream>
using namespace std;

class IntArray
{
public:
	IntArray(int s = 0);
	IntArray(IntArray &arr);
	~IntArray();
	IntArray& operator=(IntArray& right);
	//其他成员函数
	//int getV(int i);
	int &operator[](int i) {
		//返回引用
		//只能用成员函数重载，不能用友元函数重载
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
	int* pArr;  //数组首地址
	int Size;    //数组大小
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

IntArray &IntArray::operator=(IntArray& right)//拷贝构造时
{
	if (this == &right)return *this;//改进:检测是否自身调用
	delete[]pArr;
	Size = right.Size;
	if (right.pArr) {
		pArr = new int[right.Size];
		Size = right.Size;
		for (int i = 0; i < right.Size; i++) {
			pArr[i] = right.pArr[i];
		}
	}
	return *this;//支持连等运算
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
	IntArray ic= ia;//拷贝构造
	ib = ia;	//等运算符
	for (int i = 0; i < 3; i++) {
		cin >> ia[i];
	}
	//ib = ia;//系统自带:b.Size=a.Size;b.pArr=a.pArr;
	ic = ib = ia;
	//ia = ia;
	cout << ib[0]<<endl;
	cout << ic[2];
	return 0;
}