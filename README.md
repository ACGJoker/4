# 4
## 实现虚数+实数(week7_1)
- c3=c3+30;

- 转换构造
`	Complex(double r){ dReal=r;  dImag=0;}//转换构造`

- 重载运算符

`	Complex operator+(double d){return Complex(d+dReal,dImag);}`

- 友元重载运算符

`	friend Complex operator+(double d,Complex &c1);`


1．优先选择成员函数实现运算符重载 

一般情况下单目运算符重载为类的成员函数，
尤其运算符的操作需要修改对象的状态时。
双目运算符可以重载为类的成员或者友元函数:
左操作数是类对象:优先成员函数
左操作数非类对象:只能友元

- 不能用类的友元函数重载实现的运算符 = （）[] ->

2．不能重载为成员函数的运算符

当有两个不同类型的对象进行混合运算时，若双目运算符的左操作数不是A类对象，而右操作数为A类对象，则该运算符函数不能重载为A类成员函数。

当运算符函数重载为某类的成员函数时，双目运算符的左操作数，或者单目运算符的唯一操作数，必须是该类的对象或者对象的引用


 重载自增运算符的语法格式：
 
 前缀运算
 
 <函数类型>   operator ++（）；   
 
后缀运算 	

<函数类型>  operator++（int）； 


```
	Complex operator++(){//++c//返回类对象引用，不能返回局部变量引用,
			//返回引用时：可以实现++(++c)连增运算
		this->dReal=this->dReal+1;
		return *this;
	}
	Complex operator++(int){//c++//形参不能(Complex c1)，创建实参别名c1
		Complex temp(0,0);
			temp=*this;
		this->dReal=this->dReal+1;
		return temp;
	}
  ```

## []重载
```
class IntArray
{
public:
	IntArray(int s=0);
    ~IntArray();
	    //其他成员函数
private:
int * pArr;  //数组首地址
int size;    //数组大小
};
```


`int &operator[](int i) ;`
- //返回引用
- //只能用成员函数重载，不能用友元函数重载
		
## =重载

```
IntArray &IntArray::operator=(IntArray& right)
{
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
```

```
int main(){
	IntArray ia(10);
	ia=ia;//报错,避免自己调用自己
}
```

` if (this == &right)return *this;//改进:检测是否自身调用`


	IntArray ia(10), ib(5);
	IntArray ic= ia;//拷贝构造
	ib = ia;	//等运算符


## 重载>>  <<

`	friend istream& operator>>(istream& ist, IntArray& a);`

- 一定友元函数或普通的函数
- 返回流对象
- 引用

>返回流对象的引用形式istream& 或 ostream& 

> 第一个参数和函数的类型都必须是流对象引用形式
  第二个参数是要进行输出或输入操作的类对象的引用
  
> 只能将重载“>>”和“<<”的函数作为友元函数或普通的函数。


```
friend  ....

ostream& operator<<(ostream& ost, IntArray& a) {
	for (int i = 0; i < a.Size; i++)
		ost << a.pArr[i]<<" "  ;//用'cout<<'影响扩展性

	return ost;//连续输入
}
```

# 小结

- 运算符重载可以像基本数据类型一样，用简洁明确的运算符操作类对象。
- 重载运算符函数可以对运算符作出新的解释，但重原有的基本语义不变。
- 运算符函数既可以重载为成员函数，也可重载义为友员函数或普通函数。
- 当一元运算符的操作数，或者二元运算符的左操作数是该类的一个对象时，以成员函数重载；
- 当一个运算符的操作需要修改类对象状态时，应该以成员函数重载。
- 如果以成友员函数重载，可以使用引用参数修改对象。
