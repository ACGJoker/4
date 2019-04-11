#include<iostream>
using namespace std;

class IntArray
{
public:
	IntArray(int s = 0);
	IntArray(IntArray& arr);
	~IntArray();
	IntArray& operator=(IntArray& right);
	//其他成员函数
	int& operator[](int i) {
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

	//NEW
	friend istream& operator>>(istream& ist, IntArray& a);
	friend ostream& operator<<(ostream& ost, IntArray& a);
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

IntArray& IntArray::operator=(IntArray & right)//拷贝构造时
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



istream& operator>>(istream& ist, IntArray& a) {
	for (int i = 0; i < a.Size; i++)
		ist >> a.pArr[i];

	return ist;//连续输入
}
ostream& operator<<(ostream& ost, IntArray& a) {
	for (int i = 0; i < a.Size; i++)
		ost << a.pArr[i]<<" "  ;//用'cout<<'影响扩展性

	return ost;//连续输入
}

int main()
{
	IntArray ia(10), ib(5);
	IntArray ic = ia;//拷贝构造
	ib = ia;	//等运算符

	cin >> ia;
	cout << ia;

	return 0;
}