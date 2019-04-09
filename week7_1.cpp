#include <iostream>
using namespace std;
class Complex
{    
private:
	double dReal, dImag;
public:
	Complex(double r, double i){ dReal=r;  dImag=i;}
	//Complex(double r){ dReal=r;  dImag=0;}//转换构造
	Complex complexAdd(Complex c2) ;
	Complex operator+(Complex &c2){return Complex(dReal+=c2.dReal,dImag+=c2.dImag);}
	Complex operator+=(Complex &c1){
		this->dImag=this->dImag+c1.dImag;
		this->dReal=this->dReal+c1.dReal;
		return *this;
	}
	Complex operator+(double d){return Complex(d+dReal,dImag);}
	bool operator>(Complex c2){return dReal>c2.dReal;}


	void print(){cout << dReal<<'+'<<dImag<<'i'<<endl;}
	
	
	friend Complex operator+(double d,Complex &c1);//友元重载
	friend Complex operator--(Complex &c1);
	Complex& operator++(){//++c//返回类对象引用，不能返回局部变量引用,
							//返回引用时：可以实现++(++c)连增运算
		this->dReal=this->dReal+1;
		return *this;
	}
	Complex operator++(int){//c++//temp是局部变量，不能返回局部变量引用，编译通过，逻辑错误
		Complex temp(0,0);
			temp=*this;
		this->dReal=this->dReal+1;
		return temp;
	}

};

Complex operator--(Complex &c1){//--c//形参不能(Complex c1)，创建实参别名c1
	
}
Complex operator--(Complex &c1,int){//c--
	
}


Complex operator+(double d,Complex &c1){//友元重载
	return Complex(d+c1.dReal,c1.dImag);
}

Complex Complex::complexAdd(Complex c2)
{
    Complex c(0,0);
    c.dReal = dReal+c2.dReal;
    c.dImag= dImag+c2.dImag;
    return c;
}

 int main()
 {
     Complex c1(1,2),c2(3,3),c3(0,0);
  //   //c3 = c1.complexAdd(c2);
	 ////c2=c1+c2;
	 ////c2.print();
	 //if(c2>c1)
		// c2.print();
	 //else
		// c1.print();
  //   //c3.print();
	 //c3=c3+30;
	 //c3.print();
	 cout<<endl;
	 c3=(c1++);
	 c3.print();
	 

	 c3=(++c2);
	 c3.print();

	 return 0;
 }
