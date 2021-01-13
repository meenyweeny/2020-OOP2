//연산자 오버로딩
//의미를 해치는 연산자 오버로딩은 지양하자

//멤버함수를 사용한 연산자 오버로딩
/*
#include<iostream>
using namespace std;

class Complex {
public:
	Complex(int r, int i)
		:real(r), imaginary(i) {}
	Complex add(const Complex & right) {
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag);
	}
	Complex operator+(const Complex & right){ //피연산자 두개인 경우
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag);
	}
	//전위연산
	Complex operator++() {
		this->real++;
		return *this; //해당객체를 던져줌
	}
	
	//후위연산 -> 먼저 값을 리턴한 다음에 증가하는 방식
	Complex operator++(int) {
		//매개변수에 그냥 int라고 줌(후위연산임을 알리기 위해)
		Complex prev(this->real, this->imaginary);
		this->real++;
		return prev;
	}

	int Real() const { return real; }
	int Imaginary() const { return imaginary; }

private:
	int real, imaginary;
};

int main() {
	Complex c1(1, 1);
	Complex c2(7, 2);
	Complex c3(0, 0);

	//피연산자 두개인 경우(+,-,* 같이)
	//c3 = c1.add(c2); 기존의 방식, 메서드의 리턴값을 c3에 복사
	c3 = c1 + c2; //Complex타입으로 리턴받은 값이 c3가 된다
	cout << c3.Real() << ", " << c3.Imaginary() << endl;

	//피연산자 하나인 경우

	Complex init(1, 1);
	Complex prefix(0, 0);
	Complex postfix(0, 0);

	prefix = ++c1; //전위연산 //prefix = c1 = (2, 1)
	postfix = c1++; //후위연산 //postfix = (2, 1), c1 = (3, 1)
	//++의 경우엔 어떤게 전위연산이고 어떤게 후위연산인지 알 수가 없다

	cout << prefix.Real() << ", " << prefix.Imaginary() << endl;
	cout << postfix.Real() << ", " << postfix.Imaginary() << endl;
	cout << c1.Real() << ", " << c1.Imaginary() << endl;
	//핵심->전위연산과 후위연산은 별도로 만들어야 함
}
*/

//일반함수를 이용한 연산자 오버로딩

#include<iostream>
using namespace std;

class Complex {
	//친구로 지정한 함수에서는  Complex 클래스의 모든 멤버에 접근 가능
	friend Complex operator+(const Complex& left, const Complex & right);

public:
	Complex(int r, int i)
		:real(r), imaginary(i) {}
	Complex add(const Complex & right) {
		int real = this->real + right.real;
		int imag = this->imaginary + right.imaginary;
		return Complex(real, imag);
	}
	int Real() const { return real; }
	int Imaginary() const { return imaginary; }

private:
	int real, imaginary;
};

Complex operator+(const Complex& left,const Complex & right) {
	//리턴값은 Complex여야함
	//int real = left.Real() + right.Real();
	//int imag = left.Imaginary() + right.Imaginary();
	
	//friend를 통해 외부에서도 클래스의 private 멤버변수에 접근 가능
	int real = left.real + right.real;
	int imag = left.imaginary + right.imaginary;
	return Complex(real, imag);
}

int main() {
	Complex c1(1, 1);
	Complex c2(7, 2);
	Complex c3(0, 0);
	c3 = operator+(c1, c2); //c3 = c1 + c2; //둘이 같음
	cout << c3.Real() << ", " << c3.Imaginary() << endl;
}