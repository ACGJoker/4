#include <iostream>
using namespace std;
class Complex
{    
private:
	double dReal, dImag;
public:
	Complex(double r, double i){ dReal=r;  dImag=i;}
	//Complex(double r){ dReal=r;  dImag=0;}//ת������
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
	
	
	friend Complex operator+(double d,Complex &c1);//��Ԫ����
	friend Complex operator--(Complex &c1);
	Complex& operator++(){//++c//������������ã����ܷ��ؾֲ���������,
							//��������ʱ������ʵ��++(++c)��������
		this->dReal=this->dReal+1;
		return *this;
	}
	Complex operator++(int){//c++//temp�Ǿֲ����������ܷ��ؾֲ��������ã�����ͨ�����߼�����
		Complex temp(0,0);
			temp=*this;
		this->dReal=this->dReal+1;
		return temp;
	}

};

Complex operator--(Complex &c1){//--c//�ββ���(Complex c1)������ʵ�α���c1
	
}
Complex operator--(Complex &c1,int){//c--
	
}


Complex operator+(double d,Complex &c1){//��Ԫ����
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
